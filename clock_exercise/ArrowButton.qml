import QtQuick 2.15

Item {
    id: root

    signal clicked

    width: 190
    height: 101

    Image {
        id: downButton

        source: "images/btn-arrow-active.svg"
        opacity: mouseArea.containsMouse? 0: 1
        anchors.fill: parent

        Behavior on opacity {
            NumberAnimation { duration: 500 }
        }

        MouseArea {
            id: mouseArea

            anchors.fill: parent
            onClicked: root.clicked()
            hoverEnabled: true
        }
    }

    Image {
        id: hoverImage

        anchors.fill: parent
        source: "images/btn-arrow-hover.svg"
        opacity: mouseArea.containsMouse? 1: 0

        Behavior on opacity {
            NumberAnimation { duration: 500 }
        }
    }
}
