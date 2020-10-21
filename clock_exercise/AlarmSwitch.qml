import QtQuick 2.0

Rectangle {
    id: root

    property bool on: false

    signal changed

    width: 112
    height: 60
    radius: 8
    color: "#339FAAB0"

    Image {
        x: 70
        y: 17
        width: 26
        height: 26
        source: "images/223-bell.svg"
        opacity: 0.3
    }

    Rectangle {
        x: 30
        y: 18
        width: 2
        height: 22
        color: "black"
        opacity: 0.25
    }

    Image {
        x: 4
        y: 4
        source: "images/switch-off-selected.svg"
        visible: !root.on
    }

    Image {
        x: 56
        y: 4
        source: "images/switch-on-selected.svg"
        visible: root.on
    }

    MouseArea {
        anchors.fill: parent
        onClicked: root.changed()
    }
}
