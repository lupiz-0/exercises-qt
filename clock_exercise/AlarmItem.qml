import QtQuick 2.0

Column {
    id: root

    property bool lineTopVisible
    property bool everyday
    property int hours
    property int minutes
    property int day
    property int month
    property int year

    Rectangle {
        width: middleArea.width
        height: root.lineTopVisible ? lineBottom.height : 0
        color: "#182A47"
    }

    Item {
        id: middleArea

        width: 425
        height: 86

        CheckBox {
            x: 11
            anchors.verticalCenter: parent.verticalCenter
        }

        Text {
            id: dateText

            x: 84
            y: 12
            text: root.day.toString(
                      ).padStart(2, '0') + "/" + root.month.toString().padStart(
                      2, '0') + "/" + root.year.toString().padStart(2, '0')
            color: "#9FAAB0"
            font.family: "Buenos Aires"
            font.styleName: "Light"
            font.pixelSize: 18
            visible: !root.everyday
        }

        Text {
            x: dateText.x
            y: root.everyday ? 18 : 33
            text: root.hours.toString().padStart(
                      2, '0') + ":" + root.minutes.toString().padStart(2, '0')
            color: "#9FAAB0"
            font.family: "Buenos Aires"
            font.styleName: "Regular"
            font.pixelSize: 40
        }

        ActivationAlarmSwitch {
            x: 303
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    Rectangle {
        id: lineBottom

        width: middleArea.width
        height: 2
        color: "#182A47"
    }
}
