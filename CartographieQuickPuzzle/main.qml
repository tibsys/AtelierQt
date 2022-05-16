import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.12
import QtPositioning 5.12
import Carto 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Lecteur {
        onSignalNouvelleTrame: {
            //-- code à insérer
            //Réception d'un nouveau point, on fait bouger la carte
        }
    }

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    MapQuickItem {
        id: point
        sourceItem: Rectangle { width: 10; height: 10; color: "red"; border.width: 2; border.color: "red"; smooth: true; radius: 20 }
        coordinate: QtPositioning.coordinate(48.117266, -1.6777926)
        opacity: 1.0
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(48.117266, -1.6777926) // Rennes
        zoomLevel: 10

        Component.onCompleted: {
            map.addMapItem(point)
        }

        onZoomLevelChanged: {
            console.log("Zoom = " +zoomLevel)
            console.log("Radius = " +point.radius)
        }

    }
}
