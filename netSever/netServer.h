#ifndef NETSERVER_H
#define NETSERVER_H
#include<QObject>
#include<QTcpServer>
#include<QTcpSocket>
#include<QDebug>

class netServer:public QObject
{
    Q_OBJECT
public:
    netServer(QObject *Parent=nullptr):QObject(Parent)
    {

    }
    ~netServer()
    {

    }
    void init()
    {
        m_tcpSever.listen(QHostAddress::Any,1234);
        connect(&m_tcpSever,&QTcpServer::newConnection,this,[=](){
               m_tcp =m_tcpSever.nextPendingConnection();
               qDebug()<<"new connection\n";
        });
    }
private :
    QTcpServer m_tcpSever;
    QTcpSocket *m_tcp;
};

#endif // NETSERVER_H
