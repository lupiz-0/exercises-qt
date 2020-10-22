import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: barCreationNewCard

    property alias text: textArea.text

    signal createCardButtonClicked

    height: 50
    readonly property int borderWidth: 5
    color: "black"

    TextArea {
        id: textArea
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: createCardButton.left
        anchors.margins: parent.borderWidth
        background: Rectangle {
            color: "lightgreen"
        }
    }

    Button {
        id: createCardButton
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.margins: parent.borderWidth
        text: "Create card"
        onClicked: barCreationNewCard.createCardButtonClicked()
    }
}
