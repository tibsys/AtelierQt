import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Item {
    property alias mandelCanvas: mandelCanvas
    property alias lblInformation: lblInformation    

    Rectangle {
        color: "#000000"
        anchors.fill: parent

        Canvas {
            id: mandelCanvas
            anchors.fill: parent
            clip: false

            renderTarget: Canvas.FramebufferObject
            renderStrategy: Canvas.Cooperative

            Text {
                id: lblInformation
                anchors.centerIn: parent
                color: "#ffffff"
                text: qsTr("Fractales de Mandelbrot")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }
        }
    }
}
