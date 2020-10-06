import QtQuick 2.0

Rectangle {
    id: clockPage

    signal timerButtonClicked
    signal alarmButtonClicked

    color: "#151B2E"

    Text {
        x: 162
        y: 40
        width: 156
        height: 36
        text: qsTr("DeveClock")
        color: "#9FAAB0"
        font.pixelSize: 30
        horizontalAlignment: Text.AlignHCenter
        font.family: "Buenos Aires"
        font.styleName: "SemiBold"
    }

    Image {
        x: 359
        y: 43
        width: 30
        height: 33
        source: "images/timer_icon.png"
    }

    Image {
        x: 413
        y: 43
        width: 30
        height: 30
        source: "images/223-bell.svg"
    }

    Rectangle {
        x: 31
        y: 110
        width: 418
        height: 1
        color: "#9FAAB0"
    }

    Text {
        x: 122
        y: 153
        width: 236
        height: 29
        text: clockManager.dateText
        color: "#FCB647"
        font.pixelSize: 24
        horizontalAlignment: Text.AlignHCenter
        font.capitalization: Font.Capitalize
        font.family: "Buenos Aires"
        font.styleName: "Regular"
    }

    ClockFace {
        x: 31
        y: 220
        width: 418
        height: 418
    }

    ClockButton {
        x: 18
        y: 690
        text: qsTr("TIMER")
        onButtonClicked: clockPage.timerButtonClicked()
    }

    ClockButton {
        x: 272
        y: 690
        text: qsTr("ALARM")
        onButtonClicked: clockPage.alarmButtonClicked()
    }
}
