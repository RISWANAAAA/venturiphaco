//#include "mainwindow.h"
#include "prime.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    prime p;

   // MainWindow w;

    p.show();
    //p.exec();

    return a.exec();
}
