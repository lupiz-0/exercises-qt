import QtQuick 2.15

MouseArea {
    id: root

    property alias activeImageSource: downButton.source
    property alias hoverImageSource: hoverImage.source

    width: 145
    height: 145
    hoverEnabled: true

    Image {
        id: downButton

        opacity: root.containsMouse ? 0 : 1
        anchors.fill: parent

        Behavior on opacity {
            NumberAnimation {
                duration: clockManager.timeOfTheDissolveAnimation
            }
        }
    }

    Image {
        id: hoverImage

        opacity: root.containsMouse ? 1 : 0
        anchors.fill: parent

        Behavior on opacity {
            NumberAnimation {
                duration: clockManager.timeOfTheDissolveAnimation
            }
        }
    }
}
