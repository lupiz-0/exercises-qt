import QtQuick 2.15

Item {
    id: root

    property alias activeImageSource: downButton.source
    property alias hoverImageSource: hoverImage.source

    signal clicked

    width: 145
    height: 145

    Image {
        id: downButton

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
        opacity: mouseArea.containsMouse? 1: 0

        Behavior on opacity {
            NumberAnimation { duration: 500 }
        }
    }
}
