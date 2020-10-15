import QtQuick 2.0

Rectangle {
    id: root

    property bool selected
    property alias text: buttonText.text

    signal buttonClicked

    width: 192
    height: 50
    color: "#339FAAB0"
    border.color: selected ? (mouseArea.containsMouse ? "#99E2E5E7" : "#E2E5E7") : "#00E2E5E7"
    border.width: 1
    radius: height / 2

    Behavior on color {
        ColorAnimation {
            duration: clockManager.timeOfTheDissolveAnimation
        }
    }

    Behavior on border.color {
        ColorAnimation {
            duration: clockManager.timeOfTheDissolveAnimation
        }
    }

    TickOfTopAlarmButton {
        id: tick

        x: 20
        y: 8
        visualizationOfSelected: root.selected
        visualizationOfHover: mouseArea.containsMouse
    }

    Text {
        id: buttonText

        color: mouseArea.containsMouse ? "#66E2E5E7" : "#E2E5E7"
        anchors.left: tick.right
        anchors.right: root.right
        anchors.rightMargin: root.radius
        anchors.leftMargin: 10
        anchors.verticalCenter: root.verticalCenter
        font.pixelSize: 20
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
        onClicked: root.buttonClicked()
    }
}
