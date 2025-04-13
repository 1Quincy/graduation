#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include "mysql.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::init()
{
    initTcpServer();
    initUdpSocket();
}

void MainWindow::initTcpServer()
{
    tcpServer = new TcpServer(tcpPort, this);
    tcpServer->run();        //开始监听

    connect(tcpServer, &TcpServer::signalTcpMsgData, this, &MainWindow::onUdpBroadcast);
}

void MainWindow::initUdpSocket()
{
    udpSocket = new QUdpSocket(this);
}

void MainWindow::onUdpBroadcast(QByteArray &arr)
{
    /*
     * arr: 要广播的数据报
     * QHostAddress::Broadcast 广播地址，即数据报将被发送到网络上的所有主机
    *               所有在同一局域网中的主机都能接收到这个数据报
     * udpPort: 端口号，数据报应该发送到的端口
    */
    udpSocket->writeDatagram(arr, QHostAddress::Broadcast, udpPort);
}
