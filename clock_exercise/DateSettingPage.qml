import QtQuick 2.0

Rectangle {
    id: dataSettingPage

    signal back

    color: "#151B2E"

    BackButton {
        x: 28
        y: 20
        onBack: dataSettingPage.back()
    }

    TitleOfThePage {
        y: 40
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Set date")
    }

    LineUnderTitleOfThePage {
        y: 115
        anchors.horizontalCenter: parent.horizontalCenter
    }
}
