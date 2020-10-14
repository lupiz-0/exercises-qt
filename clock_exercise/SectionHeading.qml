import QtQuick 2.0

Item {
    id: root

    width: 425
    height: (clockManager.alarmItemModel.numberEverydayAlarms > 0
             && section === "false") ? 88 : 42

    Text {
        anchors.left: root.left
        anchors.leftMargin: 12
        anchors.bottom: root.bottom
        anchors.bottomMargin: 17.5
        text: section === "true" ? qsTr("Everyday") : qsTr("Others")
        color: "#FCB647"
        font.family: "Buenos Aires"
        font.styleName: "Regular"
        font.pixelSize: 20
    }

    Rectangle {
        id: lineBottom

        anchors.bottom: root.bottom
        width: root.width
        height: 2
        color: "#182A47"
    }
}
