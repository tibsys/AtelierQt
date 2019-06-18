import QtQuick 2.4

UnRectangleForm {
    id: root
    signal rectangleClicked(real xPosition, real yPosition)

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("rectangle cliqué, émission du signal: x=" +mouse.x + ", y=" +mouse.y)
            root.rectangleClicked(mouse.x, mouse.y)
        }
    }
}
