import QtQuick 2.0

Row {
    id: switchButton

    width: 160
    height: 40
    state: "unchecked"

    LocalButton {
        id: leftButton

        text: qsTr("on")
        width: parent.width/parent.children.length
        height: parent.height

        onClicked: switchButton.state = "checked"
    }
    LocalButton {
        id: rightButton

        text: qsTr("off")
        width: parent.width/parent.children.length
        height: parent.height

        onClicked: switchButton.state = "unchecked"
    }

    states: [
        State {
            name: "checked"
            PropertyChanges { target: leftButton; color: "blue"}
            PropertyChanges { target: rightButton; color: "lightgray"}
        },
        State {
            name: "unchecked"
            PropertyChanges { target: leftButton; color: "lightgray"}
            PropertyChanges { target: rightButton; color: "Darkgray"}
        }
    ]
}
