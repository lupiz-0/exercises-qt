import QtQuick 2.0

Rectangle {
    id: dataSettingPage

    signal back

    color: "#151B2E"
    Component.onCompleted: clockManager.setCurrentDate()

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
            value: clockManager.dayOfDate
            text: clockManager.dayOfDateName
            onIncrease: {
                clockManager.addToDate(1, 0, 0)
            }
            onDecrease: {
                clockManager.addToDate(-1, 0, 0)
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
            value: clockManager.monthOfDate
            text: clockManager.monthOfDateName
            onIncrease: {
                clockManager.addToDate(0, 1, 0)
            }
            onDecrease: {
                clockManager.addToDate(0, -1, 0)
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
            value: clockManager.yearOfDate
            text: qsTr("Year")
            onIncrease: {
                clockManager.addToDate(0, 0, 1)
            }
            onDecrease: {
                clockManager.addToDate(0, 0, -1)
            }
            onSetUpDownModality: {
                day.upDownModality = false
                month.upDownModality = false
                year.upDownModality = true
            }
        }
    }

    BigButton {
        x: 23
        y: 706
        text: qsTr("SET DATE")
        onButtonClicked: {
            console.log("set date ...")
        }
    }
}
