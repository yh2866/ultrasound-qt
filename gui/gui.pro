#-------------------------------------------------
#
# Project created by QtCreator 2017-10-04T02:48:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app #gui application

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
	glwidget.cpp \
        Plotter.cpp \
    data_converter.cpp \
    process.cpp

HEADERS += \
        mainwindow.h \
	glwidget.h \
        Plotter.h \
    data_converter.h \
    process.h

FORMS += \
        mainwindow.ui

RESOURCES += \
resources.qrc

INCLUDEPATH += \
./eigen-eigen-5a0156e40feb/Eigen

DISTFILES += \
    data
