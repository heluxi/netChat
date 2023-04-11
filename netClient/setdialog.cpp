#include "setdialog.h"
#include "ui_setdialog.h"
#include<QNetworkInterface>
#include<QDebug>

setDialog::setDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setDialog)
{
    ui->setupUi(this);

    auto list=QNetworkInterface::allAddresses();//返回所有主机地址
    ui->ipComboBox->clear();
    for(auto l:list)
    {
        qDebug()<<l;
        if(QAbstractSocket::IPv4Protocol== l.protocol())
            ui->ipComboBox->addItem(l.toString());
    }
}

setDialog::~setDialog()
{
    delete ui;
}

void setDialog::showEvent(QShowEvent *event)
{
    auto list=QNetworkInterface::allAddresses();//返回所有主机地址
    ui->ipComboBox->clear();
    for(auto l:list)
    {
        qDebug()<<l;
        if(QAbstractSocket::IPv4Protocol== l.protocol())
            ui->ipComboBox->addItem(l.toString());
    }

}

QString setDialog::getLocalIP()
{
    return ui->ipComboBox->currentText();
}

QString setDialog::getServerIP()
{
    return ui->serverIplineEdit->text();
}

int setDialog::getServerPort()
{
    return ui->serverPortlineEdit->text().toInt();
}


void setDialog::on_cancelButton_clicked()
{
    this->done(0);
}


void setDialog::on_okButton_clicked()
{
    this->done(1);
}

