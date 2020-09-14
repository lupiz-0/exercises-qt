import QtQuick 2.0
import QtQuick 2.15

Column {
    id: frame

    property int uniqueIdentifier
    property int selectedChapter
    property bool othersChaptersPermitOpening
    property bool permitOpeningOfAnotherChapter: selectedChapter !== uniqueIdentifier && contentText.y === frame.contentMaxHeight
    property alias contentText: contentText.text
    property alias titleText: titleText.text
    readonly property int contentMaxHeight: 200

    signal clickChapter(var idNewChapter)

    width: 160

    Rectangle {
        id: title

        width: frame.width
        height: 40
        color: "gold"

        Text {
            id: titleText

            anchors.centerIn: parent
            font.pointSize: 20
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                clickChapter(uniqueIdentifier)
            }
        }
    }

    Rectangle {
        id: content

        readonly property int animationTime: 300

        width: frame.width
        height: 0
        color: "deepskyblue"
        clip:true

        Text {
            id: contentText

            x: 0
            y: frame.contentMaxHeight
            opacity: 0
            wrapMode: Text.WordWrap
            width: content.width
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                clickChapter(uniqueIdentifier)
            }
        }
    }

    states: [
        State {
            name: "opened"
            when: frame.selectedChapter === frame.uniqueIdentifier && othersChaptersPermitOpening
        }
    ]

    transitions: [
        Transition { from: "*";  to: "opened"
            SequentialAnimation {
                NumberAnimation { target: content; property: "height"; to: frame.contentMaxHeight; duration: content.animationTime }
                ParallelAnimation {
                    NumberAnimation { target: contentText; property: "y"; to: (frame.contentMaxHeight - contentText.contentHeight)*0.5; duration: content.animationTime }
                    NumberAnimation { target: contentText; property: "opacity"; to: 1; duration: content.animationTime }
                }
            }
        },
        Transition { from: "opened"; to: "*"
            SequentialAnimation {
                ParallelAnimation {
                    NumberAnimation { target: contentText; property: "y"; to: frame.contentMaxHeight; duration: content.animationTime }
                    NumberAnimation { target: contentText; property: "opacity"; to: 0; duration: content.animationTime }
                }
                NumberAnimation { target: content; property: "height"; to: 0; duration: content.animationTime }
            }
        }
    ]
}
