import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Pane {
    property alias btnDemarrer: btnDemarrer
    property alias btnStopper: btnStopper

    RowLayout {
        Button {
            id: btnDemarrer
            text: "▶︎"
        }
        Button {
            id: btnStopper
            text: "◼︎"
        }
    }
}
