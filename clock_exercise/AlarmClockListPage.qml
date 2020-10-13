import QtQuick 2.0

Rectangle {
    id: alarmClockList

    signal back

    color: "#151B2E"
    Component.onCompleted: clockManager.alarmItemModel.setAllNotSelected()

    BackButton {
        x: 28
        y: 20
        onBack: alarmClockList.back()
    }

    TitleOfThePage {
        y: 40
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Alarm clock list")
    }

    LineUnderTitleOfThePage {
        y: 115
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 342
        visible: clockManager.alarmItemModel.rowCount() === 0
        text: qsTr("No alarm")
        color: "#9FAAB0"
        font.pixelSize: 60
        horizontalAlignment: Text.AlignHCenter
        font.family: "Buenos Aires"
        font.styleName: "Thin"
    }

    ListView {
        x: 27
        y: 133
        width: 427
        height: 625
        model: clockManager.alarmItemModel
        delegate: alarmItemDelegate
        clip: true

        section.property: "everyday"
        section.criteria: ViewSection.FullString
        section.delegate: sectionHeading
    }

    Component {
        id: sectionHeading
        SectionHeading {}
    }

    Component {
        id: alarmItemDelegate
        AlarmItem {}
    }
}
