#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpserver.h"
#include "qudpsocket.h"
#include "QStandardItemModel"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void init();
    void initTcpServer();
    void initUdpSocket();

private slots:
    void onUdpBroadcast(QByteArray& arr);

private:
    Ui::MainWindow *ui;

    //bool addMsgToDatabase(QByteArray &arr);

    TcpServer* tcpServer;
    const int tcpPort = 57777;     //tcp端口

    QUdpSocket* udpSocket;
    const int udpPort = 59999;     //udp端口

    QStandardItemModel* model;     //数据模型
};
#endif // MAINWINDOW_H
