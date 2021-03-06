import QtQuick 2.0

Rectangle {
    id: timerSettingPage

    signal back
    signal startClicked

    color: "#151B2E"

    BackButton {
        x: 28
        y: 20
        onBack: timerSettingPage.back()
    }

    TitleOfThePage {
        y: 40
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Timer")
    }

    Separator {
        y: 115
        anchors.horizontalCenter: parent.horizontalCenter
    }

    TimerUpDownNumberField {
        id: hoursNumberField

        x: 28
        y: 160
        text: qsTr("hours")
        max: 99
    }

    TimerUpDownNumberField {
        id: minutesNumberField

        x: 262
        y: 160
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

    BigButton {
        x: 23
        y: 706
        text: qsTr("START")
        active: hoursNumberField.value || minutesNumberField.value
        onButtonClicked: {
            clockManager.setTimerCurrentTime(hoursNumberField.value,
                                             minutesNumberField.value)
            clockManager.timerRunning = true
            timerSettingPage.startClicked()
        }
    }
}
