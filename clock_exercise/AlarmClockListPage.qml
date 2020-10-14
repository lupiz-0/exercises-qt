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

    LineUnderTitleOfThePage {
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
        height: deleteButton.opacity
                === 0 ? (parent.height - y - 17) : (deleteButton.y - y)
                        - 17 //i not used "anchors.bottom" instead of set height because in this way is possible animate the changing of the bottom of the "ListView"
        anchors.top: lineUnderTitleOfThePage.bottom
        anchors.topMargin: 17
        model: clockManager.alarmItemModel
        delegate: alarmItemDelegate
        clip: true
        section.property: "everyday"
        section.criteria: ViewSection.FullString
        section.delegate: sectionHeading

        Behavior on height {
            NumberAnimation {
                duration: 100
            }
        }
    }

    DeleteButton {
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
