import QtQuick 2.0

Rectangle {
    id: alarmClockList

    signal back

    color: "#151B2E"

    BackButton {
        x: 28
        y: 20
        onBack: {
            clockManager.alarmItemModel.setAllNotSelected()
            alarmClockList.back()
        }
    }

    TitleOfThePage {
        y: 40
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("Alarm clock list")
    }

    Separator {
        id: lineUnderTitleOfThePage

        y: 115
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        y: 342
        opacity: clockManager.alarmItemModel.dataCount === 0
        visible: opacity > 0
        text: qsTr("No alarm")
        color: "#9FAAB0"
        font.pixelSize: 60
        horizontalAlignment: Text.AlignHCenter
        font.family: "Buenos Aires"
        font.styleName: "Thin"

        Behavior on opacity {
            NumberAnimation {
                duration: clockManager.timeOfTheDissolveAnimation
            }
        }
    }

    ListView {
        x: 27
        width: 427
        anchors.top: lineUnderTitleOfThePage.bottom
        anchors.topMargin: 17
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 17
        model: clockManager.alarmItemModel
        delegate: alarmItemDelegate
        clip: true
        section.property: "everyday"
        section.criteria: ViewSection.FullString
        section.delegate: sectionHeading
        footer: Item {
            width: parent.width
            height: 88
        }

        Behavior on height {
            NumberAnimation {
                duration: 100
            }
        }
    }

    AlarmListPageDeleteButton {
        id: deleteButton

        x: 23
        y: 706
        onButtonClicked: clockManager.alarmItemModel.deleteSelectedAlarms()
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
