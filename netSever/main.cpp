#include <QApplication>
#include"netServer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    netServer s;
    s.init();
    return a.exec();
}
