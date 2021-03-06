import QtQuick 2.0

MouseArea {
    id: card

    property alias text: contentAreaText.text

    width: 150
    height: column.height
    drag.target: this
    drag.minimumX: 0
    drag.minimumY: 0

    Column {
        id: column

        Rectangle {
            id: topBar

            color: "green"
            width: card.width
            height: 30

            Image {
                id: closeButton

                anchors.margins: 5
                anchors.right: topBar.right
                anchors.verticalCenter: topBar.verticalCenter
                height: topBar.height - anchors.leftMargin*2
                width: height
                source: "close.png"

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        card.destroy()
                    }
                }
            }
        }

        Rectangle {
            id: contentArea

            color: "yellow"
            width: card.width
            height: 105

            Text {
                id: contentAreaText

                elide: Text.ElideRight
                wrapMode: Text.WordWrap
                anchors.fill: parent
                anchors.margins: 5
                color: "black"
            }
        }
    }
}
