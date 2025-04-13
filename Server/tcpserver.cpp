#include "tcpserver.h"
#include <qtcpsocket.h>
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "mysql.h"
#include "qsqlquery.h"
#include "QDateTime"
#include "qsqlerror.h"

TcpServer::TcpServer(int tcpPort, QObject *parent)
    : tcpPort(tcpPort),QTcpServer{parent}
{

}

bool TcpServer::run()
{
    //监听IPv4任意地址和tcpPort端口
    if (this->listen(QHostAddress::AnyIPv4, tcpPort))
    {
        qDebug() << QString("服务端监听端口 %1 成功！").arg(tcpPort) ;
        return true;
    }
    else
    {
        qDebug() << QString("服务端监听端口 %1 失败！").arg(tcpPort) ;
        return false;
    }
}

/*
* @brief: 新连接
* 当有新的连接可用时，QTcpServer调用这个虚函数
*/
void TcpServer::incomingConnection(qintptr socketDescriptor)
{
    qDebug() << QString("新的连接：%1").arg(socketDescriptor);

    QTcpSocket* socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);        //设置套接字描述符

    connect(socket, &QTcpSocket::readyRead, this, &TcpServer::readSocket);
    /*
        套接字断开连接时发出disconnected
        释放socket需要使用deleteLater()
    */
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);
}

/*
* @brief: 读取数据
* 当有新的数据可读时，读取数据并转发给QtQQ_Server
*/
void TcpServer::readSocket()
{
    QTcpSocket* socket = qobject_cast<QTcpSocket*>(sender());
    if (socket)
    {
        QByteArray buf = socket->readAll();

        qDebug()<<buf;
        if(buf.endsWith("END")) buf.chop(3);    //删除结尾的END

        QJsonDocument jsonDoc = QJsonDocument::fromJson(buf);
        if (jsonDoc.isNull() || !jsonDoc.isObject()) return;        //json格式错误
        QJsonObject jsonObj = jsonDoc.object();            //返回文档中包含的QJsonObject

        QString send = jsonObj["SEND"].toString();
        QString receive = jsonObj["RECEIVE"].toString();
        QString msg = jsonObj["MSG"].toString();
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString formattedTime = currentDateTime.toString("yyyy-MM-dd HH:mm:ss");

        //QSqlQuery sql(QString("insert into msgrecord values(%1,%2,%3,%4)").arg(send).arg(receive).arg(msg).arg(formattedTime),MySql::instance()->instance()->getDatabase());
        qDebug()<<send;
        qDebug()<<receive;
        qDebug()<<msg;
        qDebug()<<formattedTime;
        QSqlDatabase db = MySql::instance()->getDatabase();
        QSqlQuery sql(db);

        // 使用占位符（如:send, :receive）
        sql.prepare("INSERT INTO msgrecord (sendID, receiveID, message, time) "
                    "VALUES (:send, :receive, :msg, :time)");

        // 绑定参数（自动处理转义和类型）
        sql.bindValue(":send", send);
        sql.bindValue(":receive", receive);
        sql.bindValue(":msg", msg);
        sql.bindValue(":time", formattedTime);

        if (sql.exec()) {
            // 插入成功
            qDebug() << "插入成功，影响行数:" << sql.numRowsAffected();
        } else {
            // 获取详细错误信息
            QSqlError error = sql.lastError();
            qDebug() << "SQL 错误:" << error.text();
            qDebug() << "错误代码:" << error.nativeErrorCode();
        }

        if (!buf.isEmpty())
        {
            //qDebug() << QString("[send IP: %1] Data: %2").arg(socket->peerAddress().toString()).arg(QString(buf)) ;
            buf += "END";   //加上END
            emit signalTcpMsgData(buf);
            buf.clear();
        }
    }
}

