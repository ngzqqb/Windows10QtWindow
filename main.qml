
import QtQuick 2.12
import QtQuick.Controls 2.12
import sstd1 1.0

ApplicationWindow {

    id : idRoot
width: 512
height: 512
visible: true

flags: Qt.WindowMaximizeButtonHint | Qt.CustomizeWindowHint | Qt.Dialog | Qt.WindowTitleHint

Component.onCompleted: {
    //   idRoot.flags  =  Qt.FramelessWindowHint //idRoot.flags & (~Qt.WindowCloseButtonHint)

}


}


