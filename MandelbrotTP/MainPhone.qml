import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Universal 2.4
import Local 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    Universal.theme: Universal.Light
    Universal.accent: Universal.Blue

    //Pour détecter le changement d'orientation du téléphone...
    property bool isPortrait: Screen.primaryOrientation === Qt.PortraitOrientation || Screen.primaryOrientation === Qt.InvertedPortraitOrientation
    onIsPortraitChanged: {
        console.log("isPortrait", isPortrait)
        //Faire quelque chose pour changer le layout
    }

    ThreadControleur {
        id: threadControleur
        threadsCount: threadsControls.sliderThreads.value
        zoom: zoomControls.sliderZoom.value
        iterations: iterationsControls.sliderIterations.value
        largeur: canvasPane.mandelCanvas.width
        hauteur: canvasPane.mandelCanvas.height

        onSignalNouveauPoint: {
            var ctx = canvasPane.mandelCanvas.getContext("2d");
            ctx.fillStyle = point.couleur
            ctx.fillRect(point.point.x, point.point.y, 1, 1)
            canvasPane.mandelCanvas.update()
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
                    console.log("Démarrage du calcul de la fractale");
                    //Compléter le code ici pour lancer le calcul
                }

                btnStopper.onClicked: {
                    //Compléter le code ici pour stopper le calcul
                }
            }
            ThreadsControl {
                id: threadsControls
            }
        }
        FenetreForm {
            id: canvasPane
            width: isPortrait ? 300 : 600
            height: isPortrait ? 300 : 400
        }

        IterationsControl {
            id: iterationsControls
        }
        ZoomControl {
            id: zoomControls
        }
    }

}
