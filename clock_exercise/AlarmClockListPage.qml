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

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 342
        text: qsTr("No alarm")
        color: "#9FAAB0"
        font.pixelSize: 60
        horizontalAlignment: Text.AlignHCenter
        font.family: "Buenos Aires"
        font.styleName: "Thin"
    }

    ActivationAlarmSwitch {
        x: 331
        y: 189
    }
}
