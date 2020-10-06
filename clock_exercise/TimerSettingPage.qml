import QtQuick 2.0

Rectangle {
    id: timerSettingPage

    signal back

    color: "#151B2E"

    BackButton {
        id: backButton

        x: 28
        y: 20
        onBack: timerSettingPage.back()
    }

    Text {
        x: 199
        y: 40
        width: 82
        height: 36
        text: qsTr("Timer")
        color: "#9FAAB0"
        font.pixelSize: 30
        horizontalAlignment: Text.AlignHCenter
        font.family: "Buenos Aires"
        font.styleName: "SemiBold"
    }

    Rectangle {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 115
        width: 424
        height: 1
        color: "#9FAAB0"
    }

    TimerUpDownNumberField {
        id: hoursNumberField

        x: 28
        text: qsTr("hours")
        max: 99
    }

    TimerUpDownNumberField {
        id: minutesNumberField

        x: 262
        text: qsTr("mins")
        max: 59
    }

    Text {
        x: 225
        y: 199
        width: 30
        height: 143
        text: qsTr(":")
        color: "#707070"
        font.pixelSize: 120
        horizontalAlignment: Text.AlignHCenter
        font.family: "Buenos Aires"
        font.styleName: "Regular"
    }

    StartButton {
        x: 23
        y: 706
        onButtonClicked: console.log("start ...")
        enabled: hoursNumberField.value > 0 || minutesNumberField.value > 0
        text: qsTr("START")
    }
}
