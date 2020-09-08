import QtQuick 2.0

Row {
    id: switchButton

    width: 160
    height: 40
    anchors.centerIn: parent
    state: "unchecked"

    LocalButton {
        stateName: "checked"
        colorForTheStateChecked: "blue"
        colorForTheStateUnchecked: "lightgray"
        text: qsTr("on")
    }
    LocalButton {
        stateName: "unchecked"
        colorForTheStateChecked: "lightgray"
        colorForTheStateUnchecked: "Darkgray"
        text: qsTr("off")
    }

    states: [
        State {
            name: "checked"
        },
        State {
            name: "unchecked"
        }
    ]

    component LocalButton: Rectangle {
        id: button

        property string stateName: "unchecked"
        property color colorForTheStateChecked: "lightgray"
        property color colorForTheStateUnchecked: "lightgray"
        property string text: qsTr("none")

        color: switchButton.state == "checked"? colorForTheStateChecked: colorForTheStateUnchecked
        width: parent.width/parent.children.length
        height: parent.height


        Text {
            anchors.centerIn: parent
            text: button.text
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                switchButton.state = stateName
            }
        }

        Behavior on color {
            ColorAnimation {
                duration: 250
            }
        }
    }
}
