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
        initialItem: clockPage
        anchors.fill: parent
    }

    Component {
        id: clockPage
        ClockPage {
            onTimerButtonClicked: stack.push(timerSettingPage)
            onAlarmButtonClicked: {
                clockManager.dateAlarmValid = false
                clockManager.alarmEverydayModality = true
                stack.push(alarmSettingPage)
            }
            onClickOnTimerIcon: stack.push(timerPage)
            onClickOnBellIcon: stack.push(alarmClockListPage)
        }
    }

    Component {
        id: timerSettingPage
        TimerSettingPage {
            onBack: stack.pop()
            onStartClicked: stack.push(timerPage)
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
            onOpenDateSettingPage: stack.push(dateSettingPage, {
                                                  "dateObject": date
                                              })
        }
    }

    Component {
        id: dateSettingPage
        DateSettingPage {
            onBack: stack.pop()
        }
    }

    Component {
        id: alarmClockListPage
        AlarmClockListPage {
            onBack: stack.pop()
        }
    }
}
