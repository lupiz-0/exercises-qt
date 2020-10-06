import QtQuick 2.0

Item {
    id: root

    property alias text: textField.text
    property int value: 0
    property int max: 99

    y: 160
    width: 190
    height: 502

    Rectangle {
        width: 190
        height: 280
        color: "#1B2F46"
        radius: 30

        Text {
            x: 0
            y: 43
            width: 190
            height: 116
            text: root.value < 10 ? "0" + root.value : root.value
            color: "#FCB647"
            font.pixelSize: 120
            horizontalAlignment: Text.AlignHCenter
            font.family: "Buenos Aires"
            font.styleName: "Thin"
        }

        Text {
            id: textField

            x: 73
            y: 215
            width: 44
            height: 24
            color: "#9FAAB0"
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            font.family: "Buenos Aires"
            font.styleName: "Regular"
        }
    }

    ArrowButton {
        id: upButton

        y: 290
        onClicked: {
            root.value = (root.value + 1) % (root.max + 1)
        }
    }

    Rectangle {
        y: (downButton.y + downButton.height - upButton.y) * 0.5 + upButton.y - height / 2
        width: 190
        height: 2
        color: "#1B2F46"
    }

    ArrowButton {
        id: downButton

        y: 401
        rotation: 180
        onClicked: {
            root.value = root.value > 0 ? root.value - 1 : root.max
        }
    }
}
