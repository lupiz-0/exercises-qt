import QtQuick 2.0

Rectangle {
    id: background

    property real percentage: 0.33

    color: "darkgray"
    height: 40
    width: 200

    Rectangle {
        id: partVariableInExtension

        property int frameSize: 3

        color: "green"
        height: background.height - frameSize*2
        width: (background.width - frameSize*2) * background.percentage

        anchors.verticalCenter: background.verticalCenter
        anchors.left: background.left
        anchors.leftMargin: frameSize

        Behavior on width {
            NumberAnimation { duration: 1000 }
        }
    }
}
