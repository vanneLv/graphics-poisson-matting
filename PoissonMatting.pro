#-------------------------------------------------
#
# Project created by QtCreator 2016-12-06T10:55:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PoissonMatting
TEMPLATE = app

INCLUDEPATH += "D:\OpenCV\opencv\build\include"

LIBS += -LD:\OpenCV\opencv\build\x64\vc15\lib
Debug:LIBS += -lopencv_world344d
Release:LIBS += -lopencv_world344

SOURCES += main.cpp\
        mainwindow.cpp \
        poissonmatting.cpp \
    mattingcanvas.cpp

HEADERS  += mainwindow.h \
    mattingcanvas.h \
        poissonmatting.h

FORMS    += mainwindow.ui

DISTFILES += \
    README.md \
    poisson1.png \
    poisson2.png \
    poisson3.png \
    poisson4.png \
    poisson5.png \
    poisson6.png

TRANSLATIONS += poisson.ts
