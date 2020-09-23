import QtQuick 2.0
import org.example 1.0

Rectangle {
    id: root

    signal pushRecipePage

    height: 100


    Item {
        id: insetArea

        anchors.margins: 10
        anchors.fill: parent


        MouseArea {
            anchors.fill: parent
            onClicked: pushRecipePage()
        }

        Rectangle {
            id: imageFrame

            readonly property real aspectRatio: 1.5

            color: "white"
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: height*aspectRatio

            Image {
                id: image

                anchors.margins: 5
                anchors.fill: parent
                source: model.imageSource
                fillMode: Image.PreserveAspectCrop
                horizontalAlignment: Image.AlignHCenter
            }
        }

        Text {
            id: descriptionText

            anchors.left: imageFrame.right
            anchors.right: star.left
            anchors.leftMargin: 10
            text: model.description
            elide: Text.ElideRight
        }

        Image{
            id: star

            anchors.right: parent.right
            height: parent.height*0.5
            width: sourceSize.width / sourceSize.height * height
            source: preferred? "images/star_enabled.png": "images/star_disabled.png"


            MouseArea {
                anchors.fill: parent
                onClicked: model.preferred = !model.preferred
            }
        }
    }
}
