import QtQuick 2.0

Rectangle {
    id: dataSettingPage

    signal back

    color: "#151B2E"

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

        DateUpDownNumberField {
            value: clockManager.dayOfDate
            text: clockManager.dayOfDateName
            onIncrease: clockManager.addToDate(1, 0, 0)
            onDecrease: clockManager.addToDate(-1, 0, 0)
        }
        Text {
            text: " / " + clockManager.monthOfDate + " / " + clockManager.yearOfDate
            font.pixelSize: 40
            font.family: "Buenos Aires"
            font.styleName: "Regular"
            color: "#9FAAB0"
            opacity: 0.8
            height: 196
            verticalAlignment: Text.AlignBottom
        }
    }

    BigButton {
        x: 23
        y: 706
        text: qsTr("SET DATE")
        onButtonClicked: {
            clockManager.confirmAlarmDate()
            dataSettingPage.back()
        }
    }
}
