import QtQuick 2.15

MouseArea {
    id: root

    width: 190
    height: 101
    hoverEnabled: true

    Image {
        id: downButton

        source: "images/btn-arrow-active.svg"
        opacity: root.containsMouse? 0: 1
        anchors.fill: parent

        Behavior on opacity {
            NumberAnimation { duration: clockManager.timeOfTheDissolveAnimation }
        }
    }

    Image {
        id: hoverImage

        anchors.fill: parent
        source: "images/btn-arrow-hover.svg"
        opacity: root.containsMouse? 1: 0

        Behavior on opacity {
            NumberAnimation { duration: clockManager.timeOfTheDissolveAnimation }
        }
    }
}
