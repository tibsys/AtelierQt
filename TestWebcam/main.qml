import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")        

    LecteurVideo {
        id: lecteurVideo
        anchors.fill: parent
    }
}
