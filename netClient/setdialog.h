#ifndef SETDIALOG_H
#define SETDIALOG_H

#include <QDialog>

namespace Ui {
class setDialog;
}

class setDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setDialog(QWidget *parent = nullptr);
    ~setDialog();
    virtual void showEvent(QShowEvent *event);
private slots:

    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    Ui::setDialog *ui;
};

#endif // SETDIALOG_H
