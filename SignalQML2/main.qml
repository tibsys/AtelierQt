import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm {
        id: mf
        rect1.onObjectClicked: {
            console.log("Le signal objectClicked a été reçu !")
            console.log(qsTr("Emetteur : %1").arg(obj))            
        }
        rect2.onObjectClicked: {
            console.log("Le signal objectClicked a été reçu !")
            console.log(qsTr("Emetteur : %1").arg(obj))
            rect1.state = "StateBlue";
        }        

        Component.onCompleted:  {
            console.log("MainForm construit")
        }
    }

    Component.onCompleted:  {
        console.log("Démarrage terminé")
        //mf.rect1.state  = "StateBlue1";
    }

}
