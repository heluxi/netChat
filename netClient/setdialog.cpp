#include "setdialog.h"
#include "ui_setdialog.h"

setDialog::setDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setDialog)
{
    ui->setupUi(this);
}

setDialog::~setDialog()
{
    delete ui;
}

void setDialog::showEvent(QShowEvent *event)
{

}


void setDialog::on_cancelButton_clicked()
{
    this->hide();
}


void setDialog::on_okButton_clicked()
{

}

