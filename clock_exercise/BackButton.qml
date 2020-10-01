import QtQuick 2.0

Image {
    id: backButton

    signal back

    width: 80
    height: 80
    source: "images/btn-back-active.svg"
    opacity: mouseArea.containsMouse? 0.5: 1.0

    MouseArea {
        id: mouseArea

        anchors.fill: parent
        onClicked: backButton.back()
        hoverEnabled: true
    }

    Behavior on opacity {
        NumberAnimation { duration: 500 }
    }
}
