#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setGeometry( 350, 200, 1350, 750 );
    w.show();
    return a.exec();
}
