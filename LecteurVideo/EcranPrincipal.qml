import QtQuick 2.4
import QtMultimedia 5.5

EcranPrincipalForm {

    property var urls: []

    Component.onCompleted: {
        listeVideos.append({ text: "Vidéo 1", internalId: 1})
        listeVideos.append({ text: "Vidéo 2", internalId: 2})
        listeVideos.append({ text: "Vidéo 3", internalId: 3})

        //Préparation de la liste des vidéos
        urls.push("webcam")
        urls.push("http://www.sample-videos.com/video/mp4/240/big_buck_bunny_240p_10mb.mp4")
        urls.push("http://www.sample-videos.com/video/mp4/360/big_buck_bunny_360p_10mb.mp4")
        urls.push("https://filesamples.com/samples/video/avi/sample_1280x720_surfing_with_audio.avi")

        if(QtMultimedia.defaultCamera.deviceId === "") {
            listeVideos.remove(1)
        }

        ecranPrincipal.state = "Lecture"
    }

    comboListeVideos.onCurrentIndexChanged: {
        var index = comboListeVideos.currentIndex
        var idVideo = listeVideos.get(index).internalId
        var nomVideo = listeVideos.get(index).text

        if(idVideo !== -1) {
            console.log("Vidéo sélectionnée : " + nomVideo +" (" +idVideo +")")
            btnLecture.enabled = true
            opaciteLibelle.start()
        } else {
            btnLecture.enabled = false
        }        
    }

    btnLecture.onClicked: {        
        ecranPrincipal.state = "Attente";
        console.log("Lecture vidéo demandée...")
        var index = comboListeVideos.currentIndex
        var idVideo = listeVideos.get(index).internalId
        var nomVideo = listeVideos.get(index).text

        if(idVideo !== -1) {
            var url = urls[idVideo]
            console.log("URL de la vidéo : " +url)

            if(url !== "webcam") {                
                videoOutput.source = mediaplayer
                mediaplayer.source = url
                mediaplayer.play()
            } else {                                
                videoOutput.source = camera
                ecranPrincipal.state = "Lecture"
            }
        } else {
            console.error("Aucune vidéo sélectionnée");
        }
    }

    camera.onError: {
        console.log("Erreur caméra : " +camera.errorString)
    }

    camera.onCameraStateChanged: {
        if(camera.cameraState === Camera.UnloadedState || camera.cameraState === Camera.LoadedState) {
            ecranPrincipal.state = ""
            btnStop.enabled = false
        }
    }

    mediaplayer.onPlaying: {
        ecranPrincipal.state = "Lecture"
        btnStop.enabled = true
    }

    mediaplayer.onStopped: {
        ecranPrincipal.state = ""
        btnStop.enabled = false
    }

    btnStop.onClicked: {
        mediaplayer.stop()
        camera.stop()
    }

    PropertyAnimation { id: opaciteLibelle; target: text1; properties: "opacity"; to: 0.0; duration: 200}

}
