import QtQuick 2.0

Rectangle {
    id: button

    property string text: qsTr("none")

    signal clicked

    width: parent.width/parent.children.length
    height: parent.height


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
