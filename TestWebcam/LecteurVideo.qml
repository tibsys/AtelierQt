import QtQuick 2.0
import QtMultimedia 5.12
import QtQuick.Controls 2.15
import QtTest 1.12

Item {
    id: root

    Rectangle {
        id: cadreVideo
        anchors.top: parent.top
        anchors.bottom: item1.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottomMargin: 20

        color: "black"

        VideoOutput { //Afficheur vidéo
            id: videoOutput

            anchors.fill: parent
            source: camera
            onSourceChanged: console.log("Source : " +source)
            fillMode: videoOutput.PreserveAspectFit
        }

        PropertyAnimation {
            id: animationNoirBleu
        }

        PropertyAnimation {
            id: animationBleuRouge
        }

    }

    Camera { //Lecture du flux webcam = fournisseur de données pour l'afficheur
        id: camera
    }

    MediaPlayer { //Lecture du flux fichier = fournisseur de données pour l'afficheur
        id: fichier

        autoPlay: true
        source: "https://file-examples-com.github.io/uploads/2017/04/file_example_MP4_480_1_5MG.mp4"

        /*onStatusChanged: {
            var temp

            switch (playbackState)
            {
                case MediaPlayer.NoMedia:
                    temp = "MediaPlayer.NoMedia"
                break;

                case MediaPlayer.Loading:
                    temp = "MediaPlayer.Loading"
                break;

                case MediaPlayer.Loaded:
                    temp = "MediaPlayer.Loaded"
                break;

                case MediaPlayer.Buffering:
                    temp = "MediaPlayer.Buffering"
                break;

                case MediaPlayer.Stalled:
                    temp = "MediaPlayer.Stalled"
                break;

                case MediaPlayer.Buffered:
                    temp = "MediaPlayer.Buffered"
                break;

                case MediaPlayer.EndOfMedia:
                    temp = "MediaPlayer.EndOfMedia"
                break;

                case MediaPlayer.InvalidMedia:
                    temp = "MediaPlayer.InvalidMedia"
                break;

                case MediaPlayer.UnknownStatus:
                    temp = "MediaPlayer.UnknownStatus"
                break;
            }

            console.log(temp)

            if (status === MediaPlayer.Loaded)
            {
                video.play()
            }
        }
        onBufferProgressChanged: {
            console.log("Buffering: " + bufferProgress * 100)
        }
        onSourceChanged: {
            console.log("Source: " + source)
        }
        onAvailabilityChanged: {
            console.log("Availability: " + availability)
        }
        onErrorChanged: {
            console.log("Error: " + error)
        }
        onErrorStringChanged: {
            console.log("Error String: " + errorString.toString())
        }
        onHasVideoChanged: {
            console.log("Has video: " + hasVideo)
        }
        onPlaybackStateChanged: {
            var temp

            switch (playbackState)
            {
                case MediaPlayer.PlayingState:
                    temp = "MediaPlayer.PlayingState"
                break;

                case MediaPlayer.PausedState:
                    temp = "MediaPlayer.PausedState"
                break;

                case MediaPlayer.StoppedState:
                    temp = "MediaPlayer.StoppedState"
                break;
            }

            console.log(temp)
        }*/
    }

    Item {
        id: item1
        y: 466
        width: 400
        height: 50
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottomMargin: 20

        Row {
            id: column
            anchors.fill: parent

            Button {
                id: btnFichier
                text: qsTr("Fichier")
                anchors.right: parent.right
                anchors.rightMargin: 20
                highlighted: false
                flat: true

                onPressed: {
                    root.state = "lectureFichier"
                    camera.stop()
                    videoOutput.source = fichier
                    fichier.play()
                }
            }

            Button {
                id: btnCamera
                text: qsTr("Caméra")
                anchors.left: parent.left
                anchors.leftMargin: 20
                highlighted: true

                onPressed: {
                    root.state = "Default"
                    fichier.stop()
                    videoOutput.source = camera
                    camera.start()
                    animationNoirBleu.start()
                }
            }
        }
    }
    states: [
        State {
            name: "lectureFichier"

            PropertyChanges {
                target: btnCamera
                flat: true
                highlighted: false
            }

            PropertyChanges {
                target: btnFichier
                highlighted: true
                flat: false
            }
        }
    ]
    transitions: [
        Transition {
            PropertyAnimation {
                target: cadreVideo
                properties: "color";
                easing.type: Easing.InOutQuad
                from: "black"
                to: "blue"
                duration: 5000
            }
        }
    ]

    Component.onCompleted: {
        for(var i = 0 ; i < QtMultimedia.availableCameras.length ; i++) {
            console.log(QtMultimedia.availableCameras[i].displayName)
        }
    }

}



/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:6}
}
##^##*/
