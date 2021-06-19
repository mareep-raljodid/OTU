import QtQuick 2.4

Item {
    id: camera
    width: 400
    height: 400

    Flatbackground {
        id: backgroundFull
        anchors.fill: parent
        anchors.bottomMargin: 122
        anchors.rightMargin: -81
        Rectangle {
            id: rectangle
            x: 8
            y: 55
            width: 464
            height: 209
            opacity: 0.433
            color: "#ffffff"
        }
    }
}
