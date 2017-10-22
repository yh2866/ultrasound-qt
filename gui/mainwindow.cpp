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
        case Qt::Key_Right : ui->openGLWidget->rotateCameraAroundY(10); break;
        case Qt::Key_Left : ui->openGLWidget->rotateCameraAroundY(-10); break;
        case Qt::Key_Up : ui->openGLWidget->cameraZoom(1); break;
        case Qt::Key_Down : ui->openGLWidget->cameraZoom(-1); break;
    }
}
