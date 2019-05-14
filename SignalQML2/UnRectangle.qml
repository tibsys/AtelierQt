import QtQuick 2.4

UnRectangleForm {
    id: root
    signal objectClicked(Item obj)

    MouseArea {        
        anchors.fill: parent
        onClicked: {
            console.log("rectangle cliqué, émission du signal")
            console.log("mouse: " +mouse)
            console.log("parent: " +parent)
            parent.objectClicked(root)
        }
    }
}
