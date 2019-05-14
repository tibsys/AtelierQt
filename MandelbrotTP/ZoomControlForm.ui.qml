import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Pane {
    property alias sliderZoom: sliderZoom

    RowLayout {
        Text {
            id: lblZoom
            text: qsTr("Zoom :")
        }

        Text {
            id: lblTailleZoom
            text: sliderZoom.value
        }

        Slider {
            id: sliderZoom
            from: 50
            stepSize: 50
            to: 500
            value: 200
        }
    }
}
