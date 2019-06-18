import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm {
        anchors.fill: parent        

        rect.onRectangleClicked: {
            console.log("Le signal rectangleClicked a été reçu !")
            console.log("x=" +xPosition +", y=" +yPosition)
        }
    }

    Component.onCompleted:  {
        console.log("Démarrage terminé")
    }

}
