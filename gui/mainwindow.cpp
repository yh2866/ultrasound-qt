#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); //open window
    grabKeyboard();
    //QPushButton m_button = new QPushButton("Test", this);
    //m_button->setGeometry(QRect(QPoint(100, 100),QSize(200, 50)));
    //connect(zoomIn,clicked(),openGLWidget,cameraZoom(1));
    GLWidget g;

    //connect(ui->zoomIn,SIGNAL(pressed()), &temp,SLOT(cameraZoom(1)));
    QObject::connect(ui->zoomIn,SIGNAL(clicked()),ui->openGLWidget,SLOT(cameraZoomInBy1()));
    QObject::connect(ui->zoomOut,SIGNAL(clicked()),ui->openGLWidget,SLOT(cameraZoomOutBy1()));
    //connect(ui->zoomIn,SIGNAL(pressed()),this,SLOT(ui->openGLWidget->cameraZoom(1)));
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
