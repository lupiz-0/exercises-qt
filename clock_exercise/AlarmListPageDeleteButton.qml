import QtQuick 2.0

Rectangle {
    id: button

    property real hoverOpacity: mouseArea.containsMouse ? 0.75 : 1

    signal buttonClicked

    width: 434
    height: 64
    color: "#151B2E"
    border.color: "#80EC6545"
    border.width: 1
    radius: height / 2
    opacity: clockManager.alarmItemModel.numberSelectedAlarms > 0 ? hoverOpacity : 0
    visible: opacity > 0

    Behavior on opacity {
        NumberAnimation {
            duration: clockManager.timeOfTheDissolveAnimation
        }
    }

    Text {
        id: buttonText

        y: 14
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("DELETE") + " (" + clockManager.alarmItemModel.numberSelectedAlarms + ")"
        color: "#EC6545"
        font.pixelSize: 30
        horizontalAlignment: Text.AlignHCenter
        font.family: "Buenos Aires"
        font.styleName: "SemiBold"

        Behavior on opacity {
            NumberAnimation {
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
