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
}
