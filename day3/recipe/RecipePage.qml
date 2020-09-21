import QtQuick 2.0
import QtQuick.Controls 2.15

MouseArea {
    id: root

    property int difficultyId
    property int preparationTime
    property string difficultyText: switch(difficultyId){ case Recipe.Difficulty.High: return qsTr("Alta")
                                                          case Recipe.Difficulty.Mid: return qsTr("Media")
                                                          case Recipe.Difficulty.Low: return qsTr("Bassa") }
    property alias title: title.text
    property alias imageSource: image.source

    signal back

    onClicked: back()

    Rectangle {
        color: "darkgrey"
        anchors.fill: parent

        Column {
            id: column

            anchors.margins: 20
            anchors.fill: parent
            spacing: 10

            Text {
                id: title

                font.pointSize: 20
                elide: Text.ElideRight
                width: column.width
            }
            Image {
                id: image
                height: root.height - column.anchors.margins*2 - title.height - difficulty.height - preparationTime.height - column.spacing*3
                width: column.width
                horizontalAlignment: Image.AlignLeft
                fillMode: Image.PreserveAspectFit
            }
            Text {
                id: difficulty

                text: qsTr("Difficoltà: %1").arg(difficultyText)
                elide: Text.ElideRight
                width: column.width
            }
            Text {
                id: preparationTime

                text: qsTr("Tempo di preparazione: %1 minuti").arg(root.preparationTime)
                elide: Text.ElideRight
                width: column.width
            }
        }
    }
}
