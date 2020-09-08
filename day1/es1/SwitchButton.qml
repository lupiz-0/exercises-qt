import QtQuick 2.0

Row {
    id: switchButton

    width: 160
    height: 40
    state: "unchecked"

    LocalButton {
        text: qsTr("on")
        color: switchButton.state == "checked"? "blue": "lightgray"
        width: parent.width/parent.children.length
        height: parent.height

        onClicked: switchButton.state = "checked"
    }
    LocalButton {
        text: qsTr("off")
        color: switchButton.state == "checked"? "lightgray": "Darkgray"
        width: parent.width/parent.children.length
        height: parent.height

        onClicked: switchButton.state = "unchecked"
    }

    states: [
        State {
            name: "checked"
        },
        State {
            name: "unchecked"
        }
    ]
}
