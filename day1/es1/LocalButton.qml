import QtQuick 2.0

Rectangle {
    id: button

    property string text: qsTr("none")

    width: 80
    height: 40

    signal clicked

    Text {
        anchors.centerIn: parent
        text: button.text
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            button.clicked()
        }
    }

    Behavior on color {
        ColorAnimation {
            duration: 250
        }
    }
}
