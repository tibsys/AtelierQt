import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Universal 2.4
import Local 1.0

ApplicationWindow {
    visible: true
    //width: 640
    //height: 480

    Universal.theme: Universal.Light
    Universal.accent: Universal.Blue

    //Pour détecter le changement d'orientation du téléphone...
    property bool isPortrait: Screen.primaryOrientation === Qt.PortraitOrientation || Screen.primaryOrientation === Qt.InvertedPortraitOrientation
    onIsPortraitChanged: {
        console.log("isPortrait", isPortrait)
        console.log("Dimensions de l'écran : " +Screen.width +"x" +Screen.height)
        console.log("Taille du canvas : " +canvasSize())
        console.log("Device Pixel Ratio : " +Screen.devicePixelRatio)
    }

    function canvasSize() {
        return (isPortrait ? Screen.width : Screen.height);
    }

    ThreadControleur {
        id: threadControleur
        threadsCount: threadsControls.sliderThreads.value
        zoom: zoomControls.sliderZoom.value
        iterations: iterationsControls.sliderIterations.value
        largeur: canvasSize()*Screen.devicePixelRatio
        hauteur: canvasSize()*Screen.devicePixelRatio

        onSignalNouveauPoint: {
            var ctx = canvasPane.mandelCanvas.getContext("2d");
            ctx.fillStyle = point.couleur
            ctx.fillRect(point.point.x, point.point.y, Screen.devicePixelRatio, Screen.devicePixelRatio)
            canvasPane.mandelCanvas.markDirty(Qt.rect(point.point.x,point.point.y,Screen.devicePixelRatio,Screen.devicePixelRatio))
        }

        onSignalCalculDemarre: {
            console.log("Calcul démarré")
            canvasPane.lblInformation.text = ""
        }

        onSignalCalculTermine: {
            console.log("Calcul terminé")
            canvasPane.lblInformation.text = "Calcul terminé"
        }

        onSignalCalculStoppe: {
            console.log("Calcul stoppé")
            canvasPane.lblInformation.text = "Calcul stoppé"
        }
    }

    Column {
        Row {
            ActivityControl {
                id: activityControls

                btnDemarrer.onClicked: {
                    console.log("Effacement de l'écran");
                    var ctx = canvasPane.mandelCanvas.getContext("2d");
                    ctx.fillStyle = Qt.red
                    ctx.fillRect(0, 0,canvasSize()*Screen.devicePixelRatio, canvasSize()*Screen.devicePixelRatio)
                    canvasPane.mandelCanvas.markDirty(Qt.rect(0,0,canvasSize()*Screen.devicePixelRatio,canvasSize()*Screen.devicePixelRatio))
                    console.log("Démarrage du calcul de la fractale");
                    threadControleur.calculeImage();
                }

                btnStopper.onClicked: {
                    threadControleur.stoppe = true
                }
            }
            ThreadsControl {
                id: threadsControls
            }
        }
        FenetreForm {
            id: canvasPane
            width: canvasSize()
            height: canvasSize()
        }

        IterationsControl {
            id: iterationsControls
        }
        ZoomControl {
            id: zoomControls
        }
    }

}
