import QtQuick 2.0

Rectangle {
    id: dataSettingPage

    signal back

    color: "#151B2E"
    Component.onCompleted: clockManager.setCurrentDateOnTheAlarm()

    BackButton {
        x: 28
        y: 20
        onBack: dataSettingPage.back()
    }

    TitleOfThePage {
        y: 40
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Set date")
    }

    LineUnderTitleOfThePage {
        y: 115
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Row {
        y: 140
        anchors.horizontalCenter: parent.horizontalCenter

        DateNumberField {
            id: day

            numberFontSize: 120
            value: clockManager.alarmDay
            text: clockManager.alarmDayName
            onIncrease: {
                clockManager.addToAlarmDate(1, 0, 0)
            }
            onDecrease: {
                clockManager.addToAlarmDate(-1, 0, 0)
            }
            onSetUpDownModality: {
                day.upDownModality = true
                month.upDownModality = false
                year.upDownModality = false
            }
        }
        Text {
            text: " / "
            font.pixelSize: 40
            font.family: "Buenos Aires"
            font.styleName: "Regular"
            color: "#9FAAB0"
            opacity: 0.8
            height: 196
            verticalAlignment: Text.AlignBottom
        }
        DateNumberField {
            id: month

            numberFontSize: 120
            value: clockManager.alarmMonth
            text: clockManager.alarmMonthName
            onIncrease: {
                clockManager.addToAlarmDate(0, 1, 0)
            }
            onDecrease: {
                clockManager.addToAlarmDate(0, -1, 0)
            }
            onSetUpDownModality: {
                day.upDownModality = false
                month.upDownModality = true
                year.upDownModality = false
            }
        }
        Text {
            text: " / "
            font.pixelSize: 40
            font.family: "Buenos Aires"
            font.styleName: "Regular"
            color: "#9FAAB0"
            opacity: 0.8
            height: 196
            verticalAlignment: Text.AlignBottom
        }
        DateNumberField {
            id: year

            numberFontSize: 60
            value: clockManager.alarmYear
            text: qsTr("Year")
            onIncrease: {
                clockManager.addToAlarmDate(0, 0, 1)
            }
            onDecrease: {
                clockManager.addToAlarmDate(0, 0, -1)
            }
            onSetUpDownModality: {
                day.upDownModality = false
                month.upDownModality = false
                year.upDownModality = true
            }
        }
    }
}
