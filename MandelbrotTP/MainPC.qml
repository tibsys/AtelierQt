import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.2
import QtQuick.Controls.Universal 2.3
import Local 1.0

ApplicationWindow {
    visible: true
    width: 1024
    height: 768

    Universal.theme: Universal.Light
    Universal.accent: Universal.Blue

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
                    //Compléter le code ici pour démarrer le calcul
                    threadControleur.calculeImage()
                }

                btnStopper.onClicked: {
                    //Compléter le code ici pour stopper le calcul
                    threadControleur.stoppe = true
                }
            }
            ThreadsControl {
                id: threadsControls
            }
            IterationsControl {
                id: iterationsControls
            }
            ZoomControl {
                id: zoomControls
            }
        }
        FenetreForm {
            id: canvasPane
            width: 700
            height: 700
        }
    }

}
