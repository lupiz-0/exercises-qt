import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: barCreationNewCard

    property alias text: textArea.text

    signal createCardButtonClicked

    height: 50

    Rectangle {
        id: innerArea

        anchors.fill: parent
        anchors.margins: 5
        clip: true

        Row {
            id: innerAreaRow

            spacing: innerArea.anchors.margins

            TextArea {
                id: textArea

                color: "black"
                width: innerArea.width - createCardButton.width - innerArea.anchors.margins
                placeholderText: qsTr("Enter text for new card")
                background: Rectangle {
                    color: "lightgreen"
                    height: innerArea.height
                }
            }

            Button {
                id: createCardButton

                text: "Create card"
                onClicked: barCreationNewCard.createCardButtonClicked()
            }
        }
    }
}
