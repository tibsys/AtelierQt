import QtQuick 2.6
import QtQuick.Controls 2.2

Rectangle {
    property alias rect: rect

    width: 360
    height: 360

    UnRectangle {
        id: rect
    }
}
