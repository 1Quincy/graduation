#ifndef TALKWINDOW_H
#define TALKWINDOW_H

#include <QWidget>
#include "QJsonArray"
#include "QJsonObject"
#include "qtcpsocket.h"
#include "qudpsocket.h"
#include "QDateTime"

namespace Ui {
class TalkWindow;
}

class TalkWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TalkWindow(const QString& sendID,const QString& receiveID,QWidget *parent = nullptr);
    ~TalkWindow();

    void setTitle(const QString& id, const QString& p);
    void addMsg(const int& direction,const QString& sendID,const QString& receiveID,const QString& msg, QDateTime& time);
    void initTcpSocket();
    void initUdpSocket();

private slots:
    void on_sendButton_clicked();
    void sendMsgToServer(QJsonObject& obj);
    void readMsgFromServer();

signals:
    void sendMsg(QJsonObject& obj);

private:
    Ui::TalkWindow *ui;
    QString sendID;
    QString receiveID;
    QByteArray buf = "";
    QDateTime lastTime = QDateTime::fromString("2001-01-01 00:00:00","yyyy-MM-dd hh:mm:ss");
    int msgCount = 0;   //消息数量

    QTcpSocket* tcp;                 //tcp
    const int tcpPort = 57777;       //tcp端口

    QUdpSocket* udp;
    const int udpPort = 59999;       //udp端口


};

#endif // TALKWINDOW_H
