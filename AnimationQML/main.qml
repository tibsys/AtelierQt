import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    id: mainWindow
    visible: true
    width: 1000
    height: 480
    title: qsTr("Animation QML")

    Rectangle {
        id: rectangle
        x: 0
        y: mainWindow.height/2-height
        width: 100
        height: 100
        color: "#affa17"

        transform:
            Translate {
                SequentialAnimation on x {
                    loops: Animation.Infinite
                    PropertyAnimation {
                        easing.type: Easing.InOutElastic
                        easing.amplitude: 2.0
                        easing.period: 500
                        duration: 2000
                        to: mainWindow.width - rectangle.width
                    }
                    PropertyAnimation { to: 0 }
                }
            }
    }
}
