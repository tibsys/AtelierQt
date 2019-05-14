import QtQuick 2.4

Item {
    property alias rectangle: rectangle
    anchors.fill: parent

    Rectangle {
        id: rectangle
        anchors.fill: parent
        color: "#ff0000"
    }
}
