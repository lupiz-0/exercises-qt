import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

Window {
    width: 480
    height: 800
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width
    visible: true
    title: qsTr("Clock Exercise")

    StackView {
        id: stack
        initialItem: clockPage
        anchors.fill: parent
    }

    Component {
        id: clockPage
        Clock {
            onTimerButtonClicked: stack.push(timerSettingPage)
            onAlarmButtonClicked: stack.push(alarmPage)
        }
    }

    Component {
        id: timerSettingPage
        TimerSettingPage {
            onBack: stack.pop()
        }
    }


    Component {
        id: alarmPage
        AlarmPage {
            onBack: stack.pop()
        }
    }
}
