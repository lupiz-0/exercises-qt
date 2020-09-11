import QtQuick 2.0
import QtQuick 2.15

Column {
    id: frame

    property bool isExpanded: false
    property alias contentText: contentText.text
    property alias titleText: titleText.text
    property alias animationTime: content.animationTime
    readonly property int contentMaxHeight: 200

    signal clickChapter(var clickedChapter)

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
                clickChapter(frame)
            }
        }
    }

    Rectangle {
        id: content

        readonly property int animationTime: 2000

        width: frame.width
        color: "deepskyblue"
        clip:true

        Text {
            id: contentText

            x: 0
            wrapMode: Text.WordWrap
            width: content.width
            height: contentHeight
            horizontalAlignment: Text.AlignHCenter

            Behavior on y {
                NumberAnimation { duration: content.animationTime }
            }

            Behavior on opacity {
                OpacityAnimator { duration: content.animationTime }
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                clickChapter(frame)
            }
        }

        Behavior on height {
            NumberAnimation { duration: content.animationTime }
        }
    }

    states: [
        State {
            name: "compressContent"
            when: (!frame.isExpanded && contentText.y === frame.contentMaxHeight)
            PropertyChanges { target: content; height: 0}
            PropertyChanges { target: contentText; y: frame.contentMaxHeight}
            PropertyChanges { target: contentText; opacity: 0}
        },
        State {
            name: "expandContent"
            when: (frame.isExpanded && content.height < frame.contentMaxHeight)
            PropertyChanges { target: content; height: frame.contentMaxHeight}
            PropertyChanges { target: contentText; y: frame.contentMaxHeight}
            PropertyChanges { target: contentText; opacity: 0}
        },
        State {
            name: "getInText"
            when: (frame.isExpanded && content.height === frame.contentMaxHeight)
            PropertyChanges { target: content; height: frame.contentMaxHeight}
            PropertyChanges { target: contentText; y: (frame.contentMaxHeight - contentText.contentHeight)*0.5}
            PropertyChanges { target: contentText; opacity: 1}
        },
        State {
            name: "getOutText"
            when: (!frame.isExpanded && content.height > 0)
            PropertyChanges { target: content; height: frame.contentMaxHeight}
            PropertyChanges { target: contentText; y: frame.contentMaxHeight}
            PropertyChanges { target: contentText; opacity: 0}
        }
    ]
}
