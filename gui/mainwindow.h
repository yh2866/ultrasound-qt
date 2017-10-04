#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow //template
{
    Q_OBJECT //macro, allows us to create signals/slots for widgets

public:
    explicit MainWindow(QWidget *parent = 0); //constructor
    ~MainWindow(); //destructor

private:
    Ui::MainWindow *ui; //be able to access widgets
};

#endif // MAINWINDOW_H
