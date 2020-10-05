import QtQuick 2.0

Rectangle {
    id: clockPage

    signal timerButtonClicked
    signal alarmButtonClicked
    signal clickOnTimerIcon

    color: "#151B2E"

    TitleOfThePage {
        y: 40
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("DeveClock")
    }

    MouseArea {
        x: 349
        y: 33
        width: 50
        height: 50
        onClicked: clickOnTimerIcon()
        visible: clockManager.timerCurrentSeconds > 0.0

        Image {
            anchors.centerIn: parent
            width: 30
            height: 33
            source: "images/timer_icon.png"
        }
    }

    Image {
        x: 413
        y: 43
        width: 30
        height: 30
        source: "images/223-bell.svg"
    }

    LineUnderTitleOfThePage {
        y: 115
        anchors.horizontalCenter: parent.horizontalCenter
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
        alarmClockHandVisible: false
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
