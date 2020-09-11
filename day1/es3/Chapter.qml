import QtQuick 2.0

Column {
    id: frame

    property string title: "no tile"
    property string content: "no content"
    property bool isExpanded: false
    property int animationTime: 2000
    readonly property int contentMaxHeight: 200

    signal clickChapter(var clickedChapter)

    width: 160

    Rectangle {
        id: title

        width: frame.width
        height: 40
        color: "gold"

        Text {
            anchors.centerIn: parent
            text: frame.title
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

        width: frame.width
        color: "deepskyblue"
        clip:true

        Text {
            id: contentText

            x: 0
            text: frame.content
            wrapMode: Text.WordWrap
            width: content.width
            height: contentHeight
            horizontalAlignment: Text.AlignHCenter

            Behavior on y {
                NumberAnimation { duration: frame.animationTime }
            }

            Behavior on opacity {
                NumberAnimation { duration: frame.animationTime }
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                clickChapter(frame)
            }
        }

        Behavior on height {
            NumberAnimation { duration: frame.animationTime }
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
