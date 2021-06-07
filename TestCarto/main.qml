import QtQuick 2.12
import QtQuick.Window 2.12
import QtLocation 5.6
import QtPositioning 5.6

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Plugin {
        id: mapPlugin
        name: "osm" // "mapboxgl", "esri", ...
        PluginParameter {
             name: "osm.mapping.cache.directory"
             value: "/tmp/osm_cache"
        }
        PluginParameter {
             name: "osm.mapping.offline.directory"
             value: "/tmp/osm_offline"
        }
    }

    Map {
        anchors.fill: parent
        plugin: mapPlugin
        center: QtPositioning.coordinate(48.0333, -1.75) // Bruz
        zoomLevel: 14
    }
}
