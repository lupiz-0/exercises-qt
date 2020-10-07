import QtQuick 2.0

Item {
    id: root

    property bool upDownModality: false
    property alias max: numericUpDown.max
    property alias numberFontSize: numericUpDown.numberFontSize
    property alias value: numericUpDown.value

    signal setUpDownModality

    width: upDownModality ? numericUpDown.width : littleLabel.width
    height: upDownModality ? numericUpDown.height : littleLabel.height

    Text {
        id: littleLabel

        text: root.value.toString().padStart(2, '0')
        font.pixelSize: 40
        font.family: "Buenos Aires"
        font.styleName: "Regular"
        color: "#9FAAB0"
        opacity: 0.8
        height: 196
        verticalAlignment: Text.AlignBottom

        visible: !root.upDownModality
        enabled: !root.upDownModality

        MouseArea {
            anchors.fill: parent
            onClicked: root.setUpDownModality()
        }
    }

    DateUpDownNumberField {
        id: numericUpDown

        text: qsTr("Tue")
        visible: root.upDownModality
        enabled: root.upDownModality
    }
}
