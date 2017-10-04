#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w; //create an object of MainWindow class
    w.show();

    return a.exec(); //QApplication object
}
