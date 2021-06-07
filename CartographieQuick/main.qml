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
            console.log("Signal reçu dans la scène QML")
            //Mauvaise pratique : éviter de mettre du code métier dans la scène,
            //il faut le faire dans le code C++
            point.center.longitude += 0.00001
        }
    }

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    MapCircle {
        id: point
        center: QtPositioning.coordinate(48.117266, -1.6777926)
        radius: 10.0
        color: "red"
        border.width: 0
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(48.117266, -1.6777926) // Paris
        zoomLevel: 20

        Component.onCompleted: {
            map.addMapItem(point)
        }

    }
}
