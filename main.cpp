#include "MainWindow.hpp"
#include <QApplication>

#include <Windows.h>
#include <QtCore/QtCore>
#include <QtQuick>
#include <QtQml>

#include <QtQuickTemplates2/private/qquickapplicationwindow_p.h>

#include "X11x.hpp"


#include "Application1.hpp"

int main(int argc, char *argv[])  {

    int aElements[2] = {COLOR_WINDOW, COLOR_ACTIVECAPTION};
    DWORD aOldColors[2]{
        RGB(0xff,0xff,0xff),
                RGB(0x99,0xb4,0xd1)
    };
    //SetSysColors(2,aElements,aOldColors);

    DWORD aNewColors[2];

    aOldColors[0] = GetSysColor(aElements[0]);
    aOldColors[1] = GetSysColor(aElements[1]);


    qDebug() << hex << GetSysColor(COLOR_ACTIVEBORDER);
    qDebug() << hex << GetSysColor(COLOR_ACTIVECAPTION);
    qDebug() << hex << GetSysColor(COLOR_INACTIVECAPTION);

    aNewColors[0] = RGB(0x80, 0x80, 0x80);  // light gray
    aNewColors[1] = RGB(0x80, 0x00, 0x80);  // dark purple


    QApplication a(argc, argv);

    if constexpr(false){
        auto w = new X11x;
        w->show();
    }else{
        qmlRegisterType<Application1>("sstd1",1,0,"Application1");
        auto varEng = new QQmlApplicationEngine;
        varEng->load(CURRENT_QML_MAIN_DIR "/main.qml");
    }
    // SetSysColors(2, aElements, aOldColors);

    return a.exec();



}
