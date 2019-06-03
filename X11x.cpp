#include "X11x.hpp"

#include <QtCore>
#include <QtWin>
#include <Windows.h>
#include <QtGui>

X11x::X11x() {

}

void  paintPicture(HWND winId, MSG* , long *result) {
    RECT winRect1;
    RECT winRectCl;

    ::GetWindowRect(winId, &winRect1);
    ::GetClientRect(winId, &winRectCl);

    HDC hDeviceContext = ::GetWindowDC(winId);

    POINT ptTopLeft = {winRectCl.left, winRectCl.top};
    POINT ptBottomRight = {winRectCl.right, winRectCl.bottom};

    ::ClientToScreen(winId, &ptTopLeft);
    ::ClientToScreen(winId, &ptBottomRight);

    winRectCl.left = ptTopLeft.x - winRect1.left;
    winRectCl.top = ptTopLeft.y - winRect1.top;
    winRectCl.right = ptBottomRight.x - winRect1.left;
    winRectCl.bottom = ptBottomRight.y - winRect1.top;

    winRect1.right = winRect1.right - winRect1.left;
    winRect1.bottom = winRect1.bottom - winRect1.top;
    winRect1.top = 0;
    winRect1.left = 0;

    HRGN hRgnOuter = ::CreateRectRgn(winRect1.left, winRect1.top, winRect1.right, winRect1.bottom);
    HRGN hRgnInner = ::CreateRectRgn(winRectCl.left, winRectCl.top, winRectCl.right, winRectCl.bottom);
    HRGN hRgnCombine = ::CreateRectRgn(winRect1.left, winRect1.top, winRect1.right, winRect1.bottom);

    ::CombineRgn(hRgnCombine, hRgnOuter, hRgnInner, RGN_DIFF);
    ::SelectClipRgn(hDeviceContext, hRgnCombine);

    QPixmap pix(winRect1.right, winRect1.bottom);
    QPainter paint(&pix);
    QRect rc(0,0,winRect1.right, winRect1.bottom);

    paint.fillRect(rc, QColor(128,128,128));

    HBITMAP hBmp = QtWin::toHBITMAP(pix);
    HDC hDC = ::CreateCompatibleDC(hDeviceContext);
    ::SelectObject(hDC, hBmp);
    ::BitBlt(hDeviceContext, winRect1.left, winRect1.top, winRect1.right, winRect1.bottom, hDC, 0, 0, SRCCOPY);
    ::DeleteDC(hDC);
    ::DeleteObject(hBmp);

    ::DeleteObject(hRgnOuter);
    ::DeleteObject(hRgnInner);
    ::DeleteObject(hRgnCombine);
    ::ReleaseDC(winId, hDeviceContext);
    *result = 0;

}

bool X11x::nativeEvent(const QByteArray &eventType,
                       void *message,
                       long *result){

    auto varAns = QWindow::nativeEvent( eventType,message,result );

    auto varMessage =  reinterpret_cast< MSG * >(message);
    if(varMessage->message ==WM_NCPAINT ||( WM_NCACTIVATE == varMessage->message )){

        //qDebug() << "jjjx";
        auto varWinID = (HWND)(this->winId());
        paintPicture(varWinID,varMessage,result);

 return true;

    }

return varAns;

}

