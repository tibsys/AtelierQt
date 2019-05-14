import QtQuick 2.6

Rectangle {
    id: main
    property alias rect1: rect1
    property alias rect2: rect2

    width: 360
    height: 360

    UnRectangle {
        width: 100
        height: 200
        id: rect1
    }

    UnRectangle {
        width: 200
        height: 100
        anchors.left: rect1.right
        id: rect2
    }
}
