import QtQuick 2.0

Rectangle {
    id: button

    property int timeOfDissolve: 500
    property bool selected
    property alias text: buttonText.text

    signal buttonClicked

    width: 192
    height: 50
    color: "#339FAAB0"
    border.color : selected? (mouseArea.containsMouse? "#99E2E5E7": "#E2E5E7"): "#00E2E5E7"
    border.width : 1
    radius: 25

    Behavior on color {
        ColorAnimation {
            duration: button.timeOfDissolve
        }
    }

    Behavior on border.color {
        ColorAnimation {
            duration: button.timeOfDissolve
        }
    }


    TickOfTopAlarmButton {
        id: tick

        visualizationOfSelected: selected
        visualizationOfHover: mouseArea.containsMouse
    }

    Text {
        id: buttonText

        color: mouseArea.containsMouse? "#66E2E5E7": "#E2E5E7"
        anchors.left: tick.right
        anchors.right: button.right
        anchors.rightMargin: button.radius
        anchors.leftMargin: 10
        anchors.verticalCenter: button.verticalCenter
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        font.family: "Buenos Aires"
        font.styleName: "SemiBold"

        Behavior on color {
            ColorAnimation {
                duration: button.timeOfDissolve
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

