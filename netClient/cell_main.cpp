#include "cell_main.h"
#include "ui_cell_main.h"

Cell_Main::Cell_Main(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Cell_Main)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);

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
    setDialog dlg;
    dlg.exec();
}

