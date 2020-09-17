import QtQuick 2.0

Rectangle {
    id: root

    signal pushRecipePage(string title, string imageSource, int difficulty, int preparationTime)

    height: 100

    Row {
        id: insetArea

        anchors.margins: 10
        anchors.fill: parent
        spacing: anchors.margins

        Rectangle {

            readonly property real aspectRatio: 1.5

            color: "white"
            height: insetArea.height
            width: insetArea.height*aspectRatio

            Image {
                id: image

                anchors.margins: 5
                anchors.fill: parent
                source: imageSource
                fillMode: Image.PreserveAspectCrop
                horizontalAlignment: Image.AlignHCenter
            }
        }

        Text {
            width: insetArea.width - x
            text: description
            elide: Text.ElideRight
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: pushRecipePage(description, imageSource, difficulty, preparationTime)
    }
}
