import QtQuick 2.0

Rectangle {
    id: alarmSettingPage

    signal back
    signal openDateSettingPage(var date)

    color: "#151B2E"
    Component.onCompleted: clockManager.alarmDate = new Date();

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
        selected: clockManager.alarmEverydayModality
        onButtonClicked: {
            clockManager.alarmEverydayModality = true
        }
    }

    TopAlarmButton {

        property string alarmDateText: clockManager.alarmDate.toLocaleDateString( Qt.locale(), "dd/MM/yyyy")

        x: 254
        y: 140
        text: clockManager.dateAlarmValid ? alarmDateText : qsTr("Set date")
        selected: !clockManager.alarmEverydayModality
        onButtonClicked: {
            alarmSettingPage.openDateSettingPage(clockManager.alarmDate)
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
            var alarmItemData = clockManager.alarmItemModel.newAlarmItemData()

            alarmItemData.everyday = clockManager.alarmEverydayModality
            alarmItemData.active = true
            alarmItemData.selected = false
            alarmItemData.day = clockManager.alarmDay
            alarmItemData.month = clockManager.alarmMonth
            alarmItemData.year = clockManager.alarmYear
            alarmItemData.hours = alarmSlider.hours
            alarmItemData.minutes = alarmSlider.minutes

            clockManager.alarmItemModel.addNewAlarm(alarmItemData)
            alarmSettingPage.back()
        }
    }
}
