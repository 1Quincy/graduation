#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(int tcpPort, QObject *parent = nullptr);


    bool run();

protected:
    void incomingConnection(qintptr socketDescriptor) override;

signals:
    void signalTcpMsgData(QByteArray& arr);

private slots:
    void readSocket();

private:
    int tcpPort;

    //QByteArray buf = "";
};

#endif // TCPSERVER_H
