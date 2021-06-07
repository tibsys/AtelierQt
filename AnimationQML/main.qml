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
                        easing.type: Easing.InElastic
                        easing.amplitude: 2.0
                        easing.period: 500
                        duration: 2000
                        to: mainWindow.width - rectangle.width
                    }
                    PropertyAnimation {
                        to: 0
                        duration: 1500
                    }
                }

            }
    }

    Rectangle {
        id: rectangle2
        x: 0
        y: mainWindow.height - height
        width: 50
        height: 50
        color: "#17afaf"

        NumberAnimation on x {
            from: 0
            to: width
            duration: 5000
        }

    }

    Rectangle {
        id: rectangle3
        x: (mainWindow.width-width) / 2
        y: 50
        width: 75
        height: 75
        color: "yellow"

        PropertyAnimation {
            id: animCouleur
            target: rectangle3
            properties: "color"
            to: "blue"
            duration: 2000
            running: true
        }

        PropertyAnimation {
            id: transformCercle
            target: rectangle3
            properties: "radius"
            to: rectangle3.width/2
            duration: 2000
            running: true
        }


    }
}
