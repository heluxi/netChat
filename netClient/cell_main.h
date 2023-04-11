#ifndef CELL_MAIN_H
#define CELL_MAIN_H

#include <QWidget>
#include<QMouseEvent>
#include<QTcpSocket>
#include"setdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Cell_Main; }
QT_END_NAMESPACE

class Cell_Main : public QWidget
{
    Q_OBJECT

public:
    Cell_Main(QWidget *parent = nullptr);
    ~Cell_Main();

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);

    void tcpconnect();
private slots:
    void on_closeButton_clicked();

    void on_minButton_clicked();

    void on_maxButton_clicked();

    void on_setButton_clicked();

private:
    Ui::Cell_Main *ui;
    bool m_isPressed=false;
    QPoint m_winRect;
    QPoint press;
    setDialog dlg;
    QTcpSocket m_socket;
};
#endif // CELL_MAIN_H
