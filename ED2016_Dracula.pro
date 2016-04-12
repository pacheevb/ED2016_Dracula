#-------------------------------------------------
#
# Project created by QtCreator 2016-04-10T13:00:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ED2016_Dracula
TEMPLATE = app


SOURCES += main.cpp\
        ventanaprincipal.cpp \
    vcortarmazo.cpp \
    vdireccion.cpp \
    vmesa.cpp \
    AStack.cpp \
    carta.cpp \
    deck.cpp \
    tablero.cpp

HEADERS  += ventanaprincipal.h \
    vcortarmazo.h \
    vdireccion.h \
    vmesa.h \
    AStack.h \
    carta.h \
    deck.h \
    tablero.h \
    globales.h

FORMS    += ventanaprincipal.ui \
    vcortarmazo.ui \
    vdireccion.ui \
    vmesa.ui

RESOURCES += \
    recursos.qrc