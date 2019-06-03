#-------------------------------------------------
#
# Project created by QtCreator 2019-06-03T11:40:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += winextras

LIBS += -luser32
LIBS += -lgdi32

QT += quickcontrols2
QT += quickcontrols2_private
QT += qml
QT += quick
QT += qml_private
QT += quick_private
#QT += quicktemplates2
QT += quicktemplates2_private

TARGET = untitled26
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        X11x.cpp \
        main.cpp \
        MainWindow.cpp \
    Application1.cpp

HEADERS += \
        MainWindow.hpp \
        X11x.hpp \
    Application1.hpp

FORMS += \
        MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
