#include "MainWindow.hpp"
#include <QApplication>

#include <Windows.h>
#include <QtCore/QtCore>

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



    X11x w;
    w.show();

   // SetSysColors(2, aElements, aOldColors);

    return a.exec();



}
