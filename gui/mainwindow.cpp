#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); //open window
    grabKeyboard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
        case Qt::Key_Right : ui->openGLWidget->addYRotation(-30); break;
        case Qt::Key_Left : ui->openGLWidget->addYRotation(30); break;
        case Qt::Key_Up : ui->openGLWidget->addXRotation(30); break;
        case Qt::Key_Down : ui->openGLWidget->addXRotation(-30); break;
    }
}
