import QtQuick 2.0

Rectangle {
    id: dataSettingPage

    property date dateObject: new Date()
    property string dayName: dateObject.toLocaleDateString(Qt.locale(), "ddd")
    property string monthText: dateObject.toLocaleDateString(Qt.locale(), "MM")
    property string yearText: dateObject.toLocaleDateString(Qt.locale(), "yyyy")
    readonly property int dayMilliseconds: 1000 * 60 * 60 * 24

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

    Separator {
        y: 115
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Row {
        y: 140
        anchors.horizontalCenter: parent.horizontalCenter

        DateUpDownNumberField {
            value: dataSettingPage.dateObject.getDate()
            text: dataSettingPage.dayName
            onIncrease: {
                dataSettingPage.dateObject = new Date(dataSettingPage.dateObject.getTime(
                                                          ) + dataSettingPage.dayMilliseconds)
            }
            onDecrease: {
                dataSettingPage.dateObject = new Date(dataSettingPage.dateObject.getTime(
                                                          ) - dataSettingPage.dayMilliseconds)
            }
        }

        Text {
            text: " / " + dataSettingPage.monthText + " / " + dataSettingPage.yearText
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
            clockManager.alarmDate = dataSettingPage.dateObject
            clockManager.alarmEverydayModality = false
            clockManager.dateAlarmValid = true
            dataSettingPage.back()
        }
    }
}
