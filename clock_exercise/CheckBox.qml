import QtQuick 2.0

MouseArea {
    id: root

    property bool on: false

    signal changed

    width: 28
    height: 29
    onClicked: changed()

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
