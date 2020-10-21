import QtQuick 2.0

MouseArea {
    id: root

    width: 28
    height: 29
    onClicked: selected = !selected

    Image {
        anchors.fill: parent
        source: "images/check_disabled.svg"
        visible: !selected
    }

    Image {
        anchors.fill: parent
        source: "images/check_selected.svg"
        visible: selected
    }
}
