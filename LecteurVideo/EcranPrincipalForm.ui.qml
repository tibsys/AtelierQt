import QtQuick 2.4
import QtQuick.Controls 2.0
import QtMultimedia 5.5

Item {
    property alias ecranPrincipal: ecranPrincipal
    property alias listeVideos: listeVideos
    property alias comboListeVideos: comboListeVideos
    property alias btnLecture: btnLecture
    property alias btnStop: btnStop
    property alias videoOutput: videoOutput
    property alias camera: camera
    property alias mediaplayer: mediaplayer
    property alias text1: text1

    id: ecranPrincipal
    width: 400
    height: 400

    BusyIndicator {
        id: busyIndicator
        x: 170
        y: 224
        anchors.verticalCenter: videoOutput.verticalCenter
        anchors.horizontalCenter: videoOutput.horizontalCenter
        visible: false
        opacity: 0
    }

    ListModel {
        id: listeVideos
        ListElement {
            text: ""
            internalId: -1
        }
        ListElement {
            text: "Webcam locale"
            internalId: 0
        }
    }

    ComboBox {
        id: comboListeVideos
        width: 248
        height: 40
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 0
        textRole: 'text'
        model: listeVideos
    }

    Button {
        id: btnStop
        x: 390
        y: 62
        text: qsTr("Stopper")
        anchors.right: parent.right
        anchors.rightMargin: 76
        enabled: true
        anchors.left: btnLecture.right
        anchors.leftMargin: 48
    }

    Camera {
        id: camera
        position: Camera.FrontFace
        captureMode: Camera.CaptureViewfinder
    }

    MediaPlayer {
        id: mediaplayer
    }

    VideoOutput {
        id: videoOutput
        visible: false
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: btnLecture.bottom
        anchors.topMargin: 20
        source: camera
    }

    Button {
        id: btnLecture
        y: 76
        width: 100
        text: qsTr("Lire")
        anchors.left: parent.left
        anchors.leftMargin: 76
        anchors.top: comboListeVideos.bottom
        anchors.topMargin: 22
        enabled: false
        checkable: false
    }

    Text {
        id: text1
        x: 106
        y: 218
        width: 190
        height: 30
        text: qsTr("Veuillez choisir une source vidéo")
        visible: true
        font.pixelSize: 12
    }

    states: [
        State {
            name: "Attente"

            PropertyChanges {
                target: busyIndicator
                visible: true
                opacity: 1
            }

            PropertyChanges {
                target: text1
                visible: false
            }
        },
        State {
            name: "Lecture"
            PropertyChanges {
                target: busyIndicator
                visible: false
                opacity: 1
            }

            PropertyChanges {
                target: videoOutput
                visible: true
            }

            PropertyChanges {
                target: text1
                visible: false
            }
        }
    ]
}
