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

            max: 99
            numberFontSize: 120
            value: clockManager.alarmDay
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

            max: 99
            numberFontSize: 120
            value: clockManager.alarmMonth
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

            max: 9999
            numberFontSize: 60
            value: clockManager.alarmYear
            onSetUpDownModality: {
                day.upDownModality = false
                month.upDownModality = false
                year.upDownModality = true
            }
        }
    }
}
