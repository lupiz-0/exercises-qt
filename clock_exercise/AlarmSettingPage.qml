import QtQuick 2.0

Rectangle {
    id: alarmSettingPage

    property bool everydayModality: true

    signal back
    signal openDateSettingPage(var date)

    color: "#151B2E"
    Component.onCompleted: clockManager.setCurrentAlarmDate()

    BackButton {
        x: 28
        y: 20
        onBack: alarmSettingPage.back()
    }

    TitleOfThePage {
        y: 40
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Alarm")
    }

    LineUnderTitleOfThePage {
        y: 115
        anchors.horizontalCenter: parent.horizontalCenter
    }

    TopAlarmButton {
        x: 34
        y: 140
        text: qsTr("Everyday")
        selected: alarmSettingPage.everydayModality
        onButtonClicked: {
            alarmSettingPage.everydayModality = true
        }
    }

    TopAlarmButton {
        x: 254
        y: 140
        text: {
            clockManager.alarmDay.toString().padStart(
                        2, '0') + "/" + clockManager.alarmMonth.toString(
                        ).padStart(2, '0') + "/" + clockManager.alarmYear
        }
        selected: !alarmSettingPage.everydayModality
        onButtonClicked: {
            alarmSettingPage.everydayModality = false
            alarmSettingPage.openDateSettingPage(
                        new Date(clockManager.alarmYear,
                                 clockManager.alarmMonth - 1,
                                 clockManager.alarmDay))
        }
    }

    ClockFace {
        x: 88
        y: 226
        scaledWidth: 304
        scaledHeight: 304
        alarmHours: alarmSlider.hours
        alarmMinutes: alarmSlider.minutes
    }

    AlarmSlider {
        id: alarmSlider

        anchors.horizontalCenter: parent.horizontalCenter
        y: 575
    }

    BigButton {
        x: 23
        y: 706
        text: qsTr("SET ALARM")
        onButtonClicked: {
            console.log("set alarm ...")
        }
    }
}
