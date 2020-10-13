import QtQuick 2.0

Item {
    id: root

    width: 425
    height: 88

    CheckBox {
        x: 11
        anchors.verticalCenter: parent.verticalCenter
        on: selected
    }

    Text {
        id: dateText

        x: 84
        y: 12
        text: day.toString().padStart(2, '0') + "/" + month.toString().padStart(
                  2, '0') + "/" + year.toString().padStart(4, '0')
        color: "#9FAAB0"
        font.family: "Buenos Aires"
        font.styleName: "Light"
        font.pixelSize: 18
        visible: !everyday
    }

    Text {
        x: dateText.x
        y: everyday ? 18 : 33
        text: hours.toString().padStart(2, '0') + ":" + minutes.toString(
                  ).padStart(2, '0')
        color: "#9FAAB0"
        font.family: "Buenos Aires"
        font.styleName: "Regular"
        font.pixelSize: 40
    }

    ActivationAlarmSwitch {
        x: 303
        anchors.verticalCenter: parent.verticalCenter
        on: active
        onChanged: {
            active = on
        }
    }

    Rectangle {
        anchors.bottom: parent.bottom
        width: root.width
        height: 2
        color: "#182A47"
    }
}
