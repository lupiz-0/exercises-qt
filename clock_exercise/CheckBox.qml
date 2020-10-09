import QtQuick 2.0

MouseArea {
    id: root

    property bool on: false

    width: 28
    height: 29
    onClicked: {
        on = !on
    }

    Image {
        anchors.fill: parent
        source: "images/check_disabled.svg"
        visible: !root.on
    }

    Image {
        anchors.fill: parent
        source: "images/check_selected.svg"
        visible: root.on
    }
}
