import QtQuick 2.0

Rectangle {
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
