import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls.Universal 2.2

Pane {
    property alias sliderThreads: sliderThreads

    RowLayout {
        Text {
            id: lblThreads
            text: qsTr("Threads :")
        }

        Text {
            id: lblNbThreads
            text: sliderThreads.value
        }

        Slider {
            id: sliderThreads
            stepSize: 1
            to: 10
            from: 1
            value: 1
        }
    }
}
