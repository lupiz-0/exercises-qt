import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

Window {
    width: 480
    height: 800
    // ↓↓↓ to disable window resizing
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width
    // ↑↑↑ to disable window resizing
    visible: true
    title: qsTr("Clock Exercise")

    FontLoader {
        source: "fonts/BuenosAires_Family/BuenosAires-Regular.otf"
    }

    FontLoader {
        source: "fonts/BuenosAires_Family/BuenosAires-SemiBold.otf"
    }

    FontLoader {
        source: "fonts/BuenosAires_Family/BuenosAires-Bold.otf"
    }

    FontLoader {
        source: "fonts/BuenosAires_Family/BuenosAires-Black.otf"
    }

    FontLoader {
        source: "fonts/BuenosAires_Family/BuenosAires-Light.otf"
    }

    FontLoader {
        source: "fonts/BuenosAires_Family/BuenosAires-Thin.otf"
    }

    FontLoader {
        source: "fonts/BuenosAires_Family/BuenosAires-Book.otf"
    }


    StackView {
        id: stack
        initialItem: alarmSettingPage//clockPage
        anchors.fill: parent
    }

    Component {
        id: clockPage
        ClockPage {
            onTimerButtonClicked: stack.push(timerSettingPage)
            onAlarmButtonClicked: console.log("alarm button clicked")
            onClickOnTimerIcon: stack.push(timerPage)
        }
    }

    Component {
        id: timerSettingPage
        TimerSettingPage {
            onBack: stack.pop()
            onStartTimer: stack.push(timerPage)
        }
    }

    Component {
        id: timerPage
        TimerPage {
            onBack: stack.pop(null)
        }
    }

    Component {
        id: alarmSettingPage
        AlarmSettingPage {
            onBack: stack.pop()
        }
    }
}
