import QtQuick 2.0
import QtQuick 2.15

Column {
    id: frame

    property int selectedChapter
    property bool othersChaptersPermitOpening
    property alias contentText: contentText.text
    property alias titleText: titleText.text
    readonly property int contentMaxHeight: 200
    readonly property bool permitOpeningOfAnotherChapter: selectedChapter !== delegateIndex && contentText.y === frame.contentMaxHeight
    readonly property int delegateIndex: index

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
                clickChapter(delegateIndex)
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
                clickChapter(delegateIndex)
            }
        }
    }

    states: [
        State {
            name: "opened"
            when: frame.selectedChapter === frame.delegateIndex && othersChaptersPermitOpening
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
