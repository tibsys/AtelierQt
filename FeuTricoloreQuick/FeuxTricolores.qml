import QtQuick 2.0

Item {
    id: root
    width: 100
    height: 260

    Rectangle {
        id: feuRouge
        x: 10
        y: 4
        width: 80
        height: 80
        visible: false
        color: "#e94427"
        radius: 40

        Timer {
            id: timerFeuRouge
            repeat: false
            interval: 3000
            onTriggered: root.state = ""
            running: root.state == "feuRougeAllume"
        }
    }

    Rectangle {
        id: feuOrange
        x: 10
        y: 90
        width: 80
        height: 80
        visible: false
        color: "#e9b327"
        radius: 40

        Timer {
            id: timerFeuOrange
            repeat: false
            interval: 3000
            onTriggered: root.state = "feuRougeAllume"
            running: root.state == "feuOrangeAllume"
        }
    }

    Rectangle {
        id: feuVert
        x: 10
        y: 176
        width: 80
        height: 80
        color: "#18c312"
        radius: 40        

        Timer {
            id: timerFeuVert
            repeat: false
            interval: 2000
            onTriggered: root.state = "feuOrangeAllume"
            running: root.state == ""
        }
    }

    states: [
        State {
            name: "feuOrangeAllume"

            PropertyChanges {
                target: feuVert
                visible: false
            }

            PropertyChanges {
                target: feuOrange
                visible: true
            }


        },
        State {
            name: "feuRougeAllume"

            PropertyChanges {
                target: feuVert
                visible: false
            }

            PropertyChanges {
                target: feuRouge
                visible: true
            }
        }
    ]
}
