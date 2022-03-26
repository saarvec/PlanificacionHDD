QT       += core

QT       -= gui

TARGET = Listas
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

HEADERS += \
    Bienes_Raices.h \
    Cola.h \
    Lista.h \
    Nodo.h \
    Pila.h
HEADERS +=

SOURCES += main.cpp \
    Bienes_Raices.cpp

SOURCES +=

DISTFILES += \
    CframeForm.ui.qml \
    Cframe.qml

FORMS += \
    frame.ui

