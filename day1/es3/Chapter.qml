import QtQuick 2.0
import QtQuick 2.15

Column {
    id: frame

    property int uniqueIdentifier
    property int selectedChapter
    property bool othersCompressed
    property bool permitOpeningOfAnotherChapter: selectedChapter !== uniqueIdentifier && contentText.y === frame.contentMaxHeight
    //property bool permitOpeningOfAnotherChapter: (selectedChapter !== uniqueIdentifier || selectedChapter === -1) && content.height > 0
    readonly property int contentMaxHeight: 200
    property alias contentText: contentText.text
    property alias titleText: titleText.text
    property alias animationTime: content.animationTime
    


    signal clickChapter(var idNewChapter)

    width: 160
    //state: "closed"

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

        readonly property int animationTime: 2000

        width: frame.width
        height: 0
        color: "deepskyblue"
        clip:true

        Text {
            id: contentText

            x: 0
            y: frame.contentMaxHeight
            wrapMode: Text.WordWrap
            width: content.width
          //  height: contentHeight
            horizontalAlignment: Text.AlignHCenter

            //Behavior on y {
            //    NumberAnimation { duration: content.animationTime }
            //}

            //Behavior on opacity {
            //    OpacityAnimator { duration: content.animationTime }
            //}
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                clickChapter(uniqueIdentifier)
            }
        }

        //Behavior on height {
        //    NumberAnimation { duration: content.animationTime }
        //}
    }

    states: [
        State {
            name: "opened"
            when: frame.selectedChapter === frame.uniqueIdentifier && othersCompressed
        }
    ]

    transitions: [
        Transition { from: "*";  to: "opened"
            SequentialAnimation {
                NumberAnimation { target: content; property: "height"; to: frame.contentMaxHeight; duration: content.animationTime }
                NumberAnimation { target: contentText; property: "y"; to: (frame.contentMaxHeight - contentText.contentHeight)*0.5; duration: content.animationTime }
            }
        },
        Transition { from: "opened"; to: "*"
            SequentialAnimation {
                NumberAnimation { target: contentText; property: "y"; to: frame.contentMaxHeight; duration: content.animationTime }
                NumberAnimation { target: content; property: "height"; to: 0; duration: content.animationTime }
            }
        }
    ]

/*
    Timer {
        interval: 500; running: true; repeat: true
        onTriggered: console.log("state = (", frame.state, ")", content.height)
    }
    */
}
