#include "talkwindow.h"
#include "ui_talkwindow.h"
#include "mysql.h"
#include "left.h"
#include "qsqlquery.h"
#include "right.h"
#include <qmessagebox.h>
#include "qjsonobject.h"
#include "qjsondocument.h"
#include "qsqlerror.h"
#include "qtimezone.h"

TalkWindow::TalkWindow(const QString& sendID,const QString& receiveID,QWidget *parent)
    : sendID(sendID),receiveID(receiveID),QWidget(parent)
    , ui(new Ui::TalkWindow)
{
    ui->setupUi(this);
    ui -> label -> setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui -> msgWidget -> setSelectionMode(QAbstractItemView::NoSelection);
    ui -> msgWidget -> setSpacing(1);

    initTcpSocket();
    initUdpSocket();
    connect(this,&TalkWindow::sendMsg,this,&TalkWindow::sendMsgToServer);

}

TalkWindow::~TalkWindow()
{
    if (tcp) {
        tcp->disconnectFromHost();
        delete tcp;
    }
    if (udp) {
        udp->close();
        delete udp;
    }
    delete ui;
}

void TalkWindow::setTitle(const QString &id, const QString &p)
{  

    QString sql = QString("select employeeName from employeeinfo where employeeNo = %1").arg(id);
    QString name = MySql::instance()->MySql_Select(sql).at(0);
    //删除最后的“|”
    name = name.left(name.size() - 1);
    // 使用HTML格式设置内容（图片路径支持资源文件路径）
    QString html = QString("<html>"
                           "<img src='%1' width='20' height='20'/> "  // 缩放图片到100x100
                           "<span style='vertical-align: middle;'>%2</span>"      // 垂直居中文字
                           "</html>").arg(p).arg(name);

    ui->label->setText(html);
}

void TalkWindow::addMsg(const int& direction, const QString &sendID, const QString &receiveID, const QString &msg, QDateTime& time)
{
    if(direction){
        //时区设置为 UTC 时区，接着将其转换为 Asia/Shanghai（上海）时区
       /* lastTime.setTimeZone(QTimeZone::utc());
        time.setTimeZone(QTimeZone::utc());
        QTimeZone targetTimeZone("Asia/Shanghai");
        lastTime = lastTime.toTimeZone(targetTimeZone);
        time = time.toTimeZone(targetTimeZone);
       */
        //计算时间差
        qint64 secondsDifference = lastTime.secsTo(time);

        //判断是否添加时间
        if (secondsDifference > 180 && lastTime.isValid()) {
            QDateTime currentTime = QDateTime::currentDateTime();
            QDate dateToday = currentTime.date();
            QDate dateTimestamp = time.date();
            QString timeText;
            // 如果是今天
            if (dateToday == dateTimestamp) {
                QString timePart = time.time().toString("hh:mm");
                QString period = time.time().hour() < 12 ? "上午" : "下午";
                timeText = QString("%1 %2").arg(period).arg(timePart);
            }
            // 如果是昨天
            else if (dateToday == dateTimestamp.addDays(1)) {
                QString timePart = time.time().toString("hh:mm");
                QString period = time.time().hour() < 12 ? "上午" : "下午";
                timeText = QString("昨天 %1 %2").arg(period).arg(timePart);
            }
            // 如果早于昨天
            else {
                timeText = dateTimestamp.toString("yyyy-MM-dd");
            }

            //添加时间label
            QListWidgetItem* TimeItem = new QListWidgetItem;
            QLabel* timeLabel = new QLabel;
            timeLabel->setAlignment(Qt::AlignCenter);
            timeLabel->setText(timeText);
            timeLabel->adjustSize();
            TimeItem->setData(Qt::UserRole,msgCount++);
            TimeItem->setFlags(Qt::NoItemFlags);
            TimeItem->setSizeHint(timeLabel->size());
            ui->msgWidget->addItem(TimeItem);
            TimeItem->setSizeHint(timeLabel->size());
            ui->msgWidget->setItemWidget(TimeItem,timeLabel);
        }
        //更改lastTime
        lastTime = time;

        //添加发送的消息
        QListWidgetItem* ListWidgetItem = new QListWidgetItem;
        // ListWidgetItem->setSizeHint(QSize(100,30));
        ListWidgetItem->setData(Qt::UserRole,msgCount++);
        ListWidgetItem->setFlags(Qt::NoItemFlags);
        ui->msgWidget->addItem(ListWidgetItem);

        qDebug()<<"addMsg: "<<msg;
        Right* r = new Right(ui->msgWidget);
        QSqlQuery sql(QString("select employeeName,photograph from employeeinfo where employeeNo = %1").arg(sendID),MySql::instance()->getDatabase());
        if(sql.next()){
            r->setUsername(sql.value(0).toString());
            QPixmap p(sql.value(1).toString());
            r->setPhoto(p);
        }
        r->setMsg(msg);

        ListWidgetItem->setSizeHint(r->size());
        ui->msgWidget->setItemWidget(ListWidgetItem,r);
        ui->msgWidget->setCurrentItem(ListWidgetItem);

    }else{
        //计算时间差
        qint64 secondsDifference = lastTime.secsTo(time);

        //判断是否添加时间
        if (secondsDifference > 180 && lastTime.isValid()) {
            QDateTime currentTime = QDateTime::currentDateTime();
            QDate dateToday = currentTime.date();
            QDate dateTimestamp = time.date();
            QString timeText;
            // 如果是今天
            if (dateToday == dateTimestamp) {
                QString timePart = time.time().toString("hh:mm");
                QString period = time.time().hour() < 12 ? "上午" : "下午";
                timeText = QString("%1 %2").arg(period).arg(timePart);
            }
            // 如果是昨天
            else if (dateToday == dateTimestamp.addDays(1)) {
                QString timePart = time.time().toString("hh:mm");
                QString period = time.time().hour() < 12 ? "上午" : "下午";
                timeText = QString("昨天 %1 %2").arg(period).arg(timePart);
            }
            // 如果早于昨天
            else {
                timeText = dateTimestamp.toString("yyyy-MM-dd");
            }

            //添加时间label
            QListWidgetItem* TimeItem = new QListWidgetItem;
            QLabel* timeLabel = new QLabel;
            timeLabel->setAlignment(Qt::AlignCenter);
            timeLabel->setText(timeText);
            timeLabel->adjustSize();
            TimeItem->setData(Qt::UserRole,msgCount++);
            TimeItem->setFlags(Qt::NoItemFlags);
            TimeItem->setSizeHint(timeLabel->size());
            ui->msgWidget->addItem(TimeItem);
            TimeItem->setSizeHint(timeLabel->size());
            ui->msgWidget->setItemWidget(TimeItem,timeLabel);
        }
        //更改lastTime
        lastTime = time;

        //添加接受的消息
        QListWidgetItem* ListWidgetItem = new QListWidgetItem;
       // ListWidgetItem->setSizeHint(QSize(100,30));
        ListWidgetItem->setData(Qt::UserRole,msgCount++);
         ListWidgetItem->setFlags(Qt::NoItemFlags);
         ui->msgWidget->addItem(ListWidgetItem);

        qDebug()<<"addMsg: "<<msg;
        left* l = new left(ui->msgWidget);
        QSqlQuery sql(QString("select employeeName,photograph from employeeinfo where employeeNo = %1").arg(receiveID),MySql::instance()->getDatabase());
        if(sql.next()){
            l->setUsername(sql.value(0).toString());
            QPixmap p(sql.value(1).toString());
            l->setPhoto(p);
        }
        l->setMsg(msg);

        ListWidgetItem->setSizeHint(l->size());
        ui->msgWidget->setItemWidget(ListWidgetItem,l);

        ui->msgWidget->setCurrentItem(ListWidgetItem);
    }
}

void TalkWindow::initTcpSocket()
{
    tcp = new QTcpSocket(this);
    tcp->connectToHost("127.0.0.1", tcpPort);
    qDebug()<<"Tcp OK";
}

void TalkWindow::initUdpSocket()
{
    udp = new QUdpSocket(this);

    if (!udp->bind(udpPort, QAbstractSocket::ReuseAddressHint))
    {
        QMessageBox::information(nullptr, "error", "Udp socket bind Error.");
        this->close();
        return;
    }
    qDebug()<<"Udp OK";

    connect(udp, &QUdpSocket::readyRead, this, &TalkWindow::readMsgFromServer);
}

void TalkWindow::on_sendButton_clicked()
{
    if(ui->textEdit->toPlainText().isEmpty()){
        QMessageBox::information(this,"提示","请输入要发送的消息！");
        return;
    }
    QString msg = ui->textEdit->toPlainText();
    QJsonObject msgObj;
    msgObj.insert("SEND",sendID);
    msgObj.insert("RECEIVE",receiveID);
    msgObj.insert("MSG",msg);
    //msgObj.insert("FLAG","END");

    //QJsonArray msg;
    QDateTime time = QDateTime::currentDateTime();
    addMsg(1,sendID,receiveID,msg,time);
    emit sendMsg(msgObj);

    ui->textEdit->clear();

}

void TalkWindow::sendMsgToServer(QJsonObject& obj)
{
    //发送消息给服务器
    QString msg = QJsonDocument(obj).toJson(QJsonDocument::Compact);
    msg += "END";

    //qDebug() << msg;

    if (tcp->state() != QAbstractSocket::ConnectedState)        //未连接状态
    {
        QMessageBox::information(nullptr, "error", "Tcp socket connect Error.");
        return;
    }

    tcp->write(msg.toUtf8());
}

void TalkWindow::readMsgFromServer()
{
    while (udp->hasPendingDatagrams())     	//端口中有未处理的数据
    {
        //buf += udp->readAll();    //udp不可以readAll
        QByteArray msg(udp->pendingDatagramSize(), 0);      //构造一个空字节数组
        udp->readDatagram(msg.data(), msg.size());
        buf += msg;

        qDebug()<<buf;

        if(!buf.endsWith("END")){
            continue;
        }
        buf.chop(3);    //删除结尾的END

        qDebug()<<"2:"<<buf;
        QJsonDocument jsonDoc = QJsonDocument::fromJson(buf);
        if (jsonDoc.isNull() || !jsonDoc.isObject()) return;        //json格式错误
        QJsonObject jsonObj = jsonDoc.object();            //返回文档中包含的QJsonObject

        qDebug()<<sendID;
        /*   解析json对象   */
        QString sender = jsonObj["SEND"].toString();         //发送者
        QString receiver = jsonObj["RECEIVE"].toString();       //接收者
        QString message = jsonObj["MSG"].toString();
        QDateTime currentDateTime = QDateTime::currentDateTime();
        QString formattedTime = currentDateTime.toString("yyyy-MM-dd HH:mm:ss");
        if (receiver != sendID) {
            buf = "";
            return;            //只处理发送给自己的消息
        }
        addMsg(0,receiver,sender,message,currentDateTime);
        buf = "";
    }
}

