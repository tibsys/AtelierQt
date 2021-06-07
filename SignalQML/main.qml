import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    UnRectangle {
        anchors.fill: parent

        onRectangleClicked: { //SLOT - signal correspondant : rectangleClicked
            console.log("Le signal rectangleClicked a été reçu !")
            console.log("x=" +xPosition +", y=" +yPosition)
        }

        Component.onCompleted:  { //SLOT - signal correspondant completed de l'item UnRectangle
            console.log("Rectangle est construit")
        }
    }

    Component.onCompleted:  { //SLOT - signal correspondant completed de l'item Window
        console.log("Démarrage terminé")
    }

}
