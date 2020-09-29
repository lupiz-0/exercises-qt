import QtQuick 2.0
import QtQuick.Controls 2.15

Rectangle {
    id: timerSettingPage

    signal back

    color: "#151B2E"

    Rectangle {
        id: backButton

        width: 100
        height: 50
        color: "#FCB647"

        MouseArea {
            anchors.fill: parent
            onClicked: back()
        }
    }

    Text {
        text: "timer page"
        color: "#FCB647"
        anchors.centerIn: parent
        font.pixelSize: 30
        horizontalAlignment: Text.AlignHCenter
    }
}
