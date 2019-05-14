import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Pane {
    property alias sliderIterations: sliderIterations

    RowLayout {
        Text {
            id: lblIterations
            text: qsTr("Itérations :")
        }

        Text {
            id: lblNbIterations
            text: sliderIterations.value
            font.bold: true
        }

        Slider {
            id: sliderIterations
            from: 1
            stepSize: 10
            to: 200
            value: 50
        }
    }
}
