import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import QtQuick.Dialogs 1.2
import alefbet 1.1

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("FichierQML")

    Text {
        id: text1
        x: 13
        width: 607
        text: qsTr("Le texte chargé s'affichera ici")
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        font.pixelSize: 12
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 75
        anchors.topMargin: 17
    }

    FileDialog {
        id: fileDialog

        onAccepted: {
            console.log("Fichier sélectionné : " +fileDialog.fileUrl)
            text1.text = fileController.readFile(fileDialog.fileUrl)
        }
    }

    ChargeurDeFichier {
        id: fileController;
    }

    Button {
        id: button
        x: 267
        y: 429
        text: qsTr("Charger...")
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 11

        onClicked: {
            console.log("Ouverture de la boite de sélection")
            fileDialog.open()
        }
    }
}
