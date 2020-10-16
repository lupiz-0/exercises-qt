import QtQuick 2.0

Item {
    id: root

    property alias text: textField.text
    property int value

    signal increase
    signal decrease

    width: 190
    height: 512

    Rectangle {
        width: 190
        height: 290
        color: "#1B2F46"
        radius: 30

        Text {
            id: textField

            x: 61
            y: 45
            width: 68
            height: 48
            color: "#9FAAB0"
            font.pixelSize: 40
            horizontalAlignment: Text.AlignHCenter
            font.family: "Buenos Aires"
            font.styleName: "Regular"
            font.capitalization: Font.Capitalize
        }

        Text {
            x: 0
            y: 104
            width: 190
            height: 135
            text: root.value.toString().padStart(2, '0')
            color: "#FCB647"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.family: "Buenos Aires"
            font.styleName: "Thin"
            font.pixelSize: 120
        }
    }

    ArrowButton {
        id: upButton

        y: 300
        onClicked: root.increase()
    }

    Rectangle {
        y: (downButton.y + downButton.height - upButton.y) * 0.5 + upButton.y - height / 2
        width: 190
        height: 2
        color: "#1B2F46"
    }

    ArrowButton {
        id: downButton

        y: 411
        rotation: 180
        onClicked: root.decrease()
    }
}
