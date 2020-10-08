import QtQuick 2.0

Rectangle {
    id: alarmClockList

    signal back

    color: "#151B2E"

    BackButton {
        x: 28
        y: 20
        onBack: alarmClockList.back()
    }

    TitleOfThePage {
        y: 40
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Alarm clock list")
    }

    LineUnderTitleOfThePage {
        y: 115
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
