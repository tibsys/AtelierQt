import QtQuick 2.4

Item {
    id: root // Item root;
    anchors.fill: parent
    signal rectangleClicked(real xPosition, real yPosition)

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "#ff0000"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                console.log("rectangle cliqué, émission du signal: x=" +mouse.x + ", y=" +mouse.y)
                root.rectangleClicked(mouse.x, mouse.y)
            }
        }
    }

}
