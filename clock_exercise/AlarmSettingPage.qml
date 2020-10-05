import QtQuick 2.0

Rectangle {
    id: alarmSettingPage

    property bool everydayModality: true

    signal back

    color: "#151B2E"

    BackButton {
        x: 28; y: 20
        onBack: alarmSettingPage.back()
    }

    TitleOfThePage {
        y: 40; anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Alarm")
    }

    LineUnderTitleOfThePage {
        y: 115; anchors.horizontalCenter: parent.horizontalCenter
    }

    TopAlarmButton {
        x: 34; y: 140
        text: qsTr("Everyday")
        selected: everydayModality
        onButtonClicked: {everydayModality = true}
    }

    TopAlarmButton {
        x: 254; y: 140
        text: qsTr("date")
        selected: !everydayModality
        onButtonClicked: {everydayModality = false}
    }

    ClockFace {
        x: 88; y: 226
        scaledWidth: 304
        scaledHeight: 304
    }

    AlarmSlider {
        x: 18; y:598
    }
}
