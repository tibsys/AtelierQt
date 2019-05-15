import QtQuick 2.4
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

Pane {
    property alias btnDemarrer: btnDemarrer
    property alias btnStopper: btnStopper
    property alias chkOptimise: chkOptimise

    RowLayout {
        Button {
            id: btnDemarrer
            width: 30
            text: "▶︎"
            Layout.preferredWidth: 30
        }
        Button {
            id: btnStopper
            width: 30
            text: "◼︎"
            Layout.preferredWidth: 30
        }

        CheckBox {
            id: chkOptimise
            text: qsTr("Optimisé")
        }
    }
}




/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
