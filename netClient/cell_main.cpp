#include "cell_main.h"
#include "ui_cell_main.h"

Cell_Main::Cell_Main(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell_Main)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);

    auto fcon=[&](){
        auto ip=m_socket.localAddress().toString();
        ui->textBrowser->append(ip+"连接成功");
    };
    connect(&m_socket,&QAbstractSocket::connected,this,fcon);
    auto fdiscon=[&](){
        auto ip=m_socket.localAddress().toString();
        ui->textBrowser->append(ip+"连接失败");
    };
    connect(&m_socket,&QAbstractSocket::disconnected,this,fcon);
}

Cell_Main::~Cell_Main()
{
    delete ui;
}

void Cell_Main::mousePressEvent(QMouseEvent *event)
{
    auto rect=ui->titleframe->geometry();
    QPoint p=event->pos();
    if(rect.contains(p))
    {
        m_isPressed=true;
        m_winRect=this->geometry().topLeft();

        press=this->mapToGlobal(p);

    }

}

void Cell_Main::mouseReleaseEvent(QMouseEvent *event)
{

        m_isPressed=false;

}

void Cell_Main::mouseMoveEvent(QMouseEvent *event)
{
    if(m_isPressed)
    {
        auto v=mapToGlobal(event->pos())-press;
        auto r=m_winRect;
        this->move(r+v);
    }
}

void Cell_Main::tcpconnect()
{
    auto local_ip=dlg.getLocalIP();
    auto server_ip=dlg.getServerIP();
    auto server_port=dlg.getServerPort();
    m_socket.close();
    m_socket.bind(QHostAddress(local_ip));
    m_socket.connectToHost(server_ip,server_port);



}


void Cell_Main::on_closeButton_clicked()
{
    exit(0);
}


void Cell_Main::on_minButton_clicked()
{
    showMinimized();
}


void Cell_Main::on_maxButton_clicked()
{

}


void Cell_Main::on_setButton_clicked()
{

    int rec=dlg.exec();
    if(rec)
    {
        tcpconnect();
        qDebug()<<"local ip"<<dlg.getLocalIP();
        qDebug()<<"server ip"<<dlg.getServerIP();
        qDebug()<<"server port"<<dlg.getServerPort();
    }
}

