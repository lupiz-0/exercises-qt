import QtQuick 2.0

Rectangle {
    id: button

    property bool enabled: true

    property alias text: buttonText.text

    signal buttonClicked

    width: 434
    height: 64
    color: button.enabled ? (mouseArea.containsMouse ? "#9900A6E2" : "#00A6E2") : "#0000A6E2"
    border.color: button.enabled ? (mouseArea.containsMouse ? "9900A6E2" : "#00A6E2") : "#8000A6E2"
    border.width: 1
    radius: 32

    Behavior on color {
        ColorAnimation {
            duration: clockManager.timeOfTheDissolveAnimation
        }
    }

    Text {
        id: buttonText

        width: 98
        height: 36
        color: button.enabled ? (mouseArea.containsMouse ? "#99FFFFFF" : "#FFFFFF") : "#8000A6E2"
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
        onClicked: {
            if (button.enabled)
                button.buttonClicked()
        }
    }
}
