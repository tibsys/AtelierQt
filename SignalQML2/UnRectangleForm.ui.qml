import QtQuick 2.4

Item {
    Rectangle {
        id: rectangle
        color: "#ff0000"
        anchors.fill: parent
        border.width: 3
        border.color: "#000"
    }

    Text {
        id: text1
        text: qsTr("Text")
        font.pixelSize: 12
        opacity: 0

        MouseArea {
            id: ma
            anchors.fill: parent
        }
    }
    states: [
        State {
            name: "StateBlue"

            PropertyChanges {
                target: rectangle
                color: "#410bab"
            }

            when: text1.ma.clicked
        },
        State {
            name: "StateBlue1"
            PropertyChanges {
                target: rectangle
                x: 20
                y: 40
                width: 100
                height: 100
                color: "#9172d1"
            }

            PropertyChanges {
                target: text1
                width: 60
                height: 40
                opacity: 1
            }
        }
    ]
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
