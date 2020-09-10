import QtQuick 2.0

Column {
    id: frame


    property string title: "no tile"
    property string content: "no content"
    property bool isExpanded: false
    readonly property int contentMaxHeight: 200
    //readonly property int animationTime: 300
    readonly property int animationTime: 2000

    width: 160
    //state: expandedState
    state: "compressedState"


    signal clickChapter(var sender)

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
        //height: 200
        color: "deepskyblue"

        Text {
            id: contentText

            readonly property int heightOfTheFullText: 140

            //anchors.centerIn: parent
            x: 0
            //y: (content.height - height) * 0.5
            //y: content.height
            text: frame.content
            wrapMode: Text.WordWrap
            width: content.width
            height: content.height - y
            horizontalAlignment: Text.AlignHCenter
            //verticalAlignment: Text.AlignVCenter
            clip:true
            state: "getOut"


            states: [
                State {
                    name: "getIn"
                    when: (frame.isExpanded && content.height === frame.contentMaxHeight)
                    PropertyChanges
                    {
                        target: contentText; y: (frame.contentMaxHeight - contentText.heightOfTheFullText)*0.5
                    }
                    PropertyChanges { target: contentText; opacity: 1}
                },
                State {
                    name: "getOut"
                    when: (!frame.isExpanded || frame.isExpanded && content.height !== frame.contentMaxHeight)
                    PropertyChanges
                    {
                        target: contentText; y: frame.contentMaxHeight
                    }
                    PropertyChanges { target: contentText; opacity: 0}
                }
            ]


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
            when: (!frame.isExpanded)
            PropertyChanges { target: content; height: 0}
        },
        State {
            name: "expandContent"
            when: (frame.isExpanded)
            PropertyChanges { target: content; height: frame.contentMaxHeight}
        }
        /*
        State {
            name: "compressContent"
            when: (frame.isExpanded == false && contentText.y == frame.contentMaxHeight)
            PropertyChanges { target: content; height: 0}
            PropertyChanges { target: contentText; y: frame.contentMaxHeight}
            PropertyChanges { target: contentText; opacity: 0}
        },
        State {
            name: "expandContent"
            when: (frame.isExpanded == true && content.height < frame.contentMaxHeight)
            PropertyChanges { target: content; height: frame.contentMaxHeight}
            PropertyChanges { target: contentText; y: frame.contentMaxHeight}
            PropertyChanges { target: contentText; opacity: 0}
        },
        State {
            name: "getInText"
            when: (frame.isExpanded == true && content.height == frame.contentMaxHeight)
            PropertyChanges { target: content; height: frame.contentMaxHeight}
            PropertyChanges { target: contentText; y: (frame.contentMaxHeight - contentText.heightOfTheFullText)*0.5}
            PropertyChanges { target: contentText; opacity: 1}
        },
        State {
            name: "getOutText"
            when: (frame.isExpanded == false && content.height > 0)
            PropertyChanges { target: content; height: frame.contentMaxHeight}
            PropertyChanges { target: contentText; y: frame.contentMaxHeight}
            PropertyChanges { target: contentText; opacity: 0}
        }
        */
    ]



    Timer {
        interval: 500;
        running: true;
        repeat: true
        onTriggered: {
            console.log("y = ", contentText.y)
        }
    }
}
