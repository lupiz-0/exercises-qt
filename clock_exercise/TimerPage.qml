import QtQuick 2.0

Rectangle {
    id: timerPage

    property int timerHours: (clockManager.timerCurrentSeconds
                              / clockManager.secondsInOneMinute) / 60
    property int timerMinutes: (clockManager.timerCurrentSeconds
                                / clockManager.secondsInOneMinute) % 60

    signal back

    color: "#151B2E"

    BackButton {
        x: 28
        y: 20
        onBack: timerPage.back()
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

    Text {
        y: 300
        anchors.horizontalCenter: parent.horizontalCenter
        text: timerPage.timerHours.toString().padStart(
                  2, '0') + ":" + timerPage.timerMinutes.toString(
                  ).padStart(2, '0')
        color: "#FCB647"
        font.pixelSize: 120
        horizontalAlignment: Text.AlignHCenter
        font.family: "Buenos Aires"
        font.styleName: "Thin"
    }

    TimerButton {
        x: 60
        y: 594
        activeImageSource: "images/btn-reload-active.svg"
        hoverImageSource: "images/btn-reload-hover.svg"
        onClicked: clockManager.restartTimer()
    }

    TimerButton {
        id: buttonPause

        x: 275
        y: 594
        activeImageSource: "images/btn-pause-active.svg"
        hoverImageSource: "images/btn-pause-hover.svg"
        onClicked: {
            clockManager.timerRunning = false
        }
        visible: clockManager.timerRunning
    }

    TimerButton {
        x: buttonPause.x
        y: buttonPause.y
        activeImageSource: "images/btn-play-active.svg"
        hoverImageSource: "images/btn-play-hover.svg"
        onClicked: {
            clockManager.timerRunning = true
        }
        visible: !clockManager.timerRunning
    }
}
