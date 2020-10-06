import QtQuick 2.0

Rectangle {
    id: button

    property alias text: buttonText.text

    signal buttonClicked

    width: 190
    height: 64
    color: mouseArea.containsMouse? "#FCB647": "#151B2E"
    border.color : "#FCB647"
    border.width : 1
    radius: 32

    Behavior on color {
        ColorAnimation {
            duration: clockManager.timeOfTheDissolveAnimation
        }
    }

    Text {
        id: buttonText

        width: 96
        height: 36
        color: mouseArea.containsMouse? "#151B2E": "#FCB647"
        anchors.centerIn: parent
        font.pixelSize: 30
        horizontalAlignment: Text.AlignHCenter
        font.family: "Buenos Aires"
        font.styleName: "SemiBold"

        Behavior on color {
            ColorAnimation {
                duration: clockManager.timeOfTheDissolveAnimation
            }
        }
    }

    MouseArea {
        id: mouseArea

        hoverEnabled: true
        anchors.fill: parent
        onClicked: button.buttonClicked()
    }
}

