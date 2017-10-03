#include <QApplication>
#include <QLabel>

int main(int argc, char* argv[]) {
    QApplication app(argc,argv);
    QLabel *label = new QLabel("Image");
    label->setWindowTitle("3D Ultrasound Project");
    label->resize(400,400);
    label->show();
    return app.exec();
}
