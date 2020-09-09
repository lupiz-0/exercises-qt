import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Bar exercise")


    property var percentages: [
        Math.random(), Math.random(), Math.random(), Math.random(), Math.random()
    ]

    Column {
        anchors.centerIn: parent
        spacing: 5

        Bar {
            percentage: percentages[0]
        }
        Bar {
            percentage: percentages[1]
        }
        Bar {
            percentage: percentages[2]
        }
        Bar {
            percentage: percentages[3]
        }
        Bar {
            percentage: percentages[4]
        }
    }

    Timer {
        interval: 500;
        running: true;
        repeat: true
        onTriggered: {
            var newPercentages = []
            for(var i = 0; i < percentages.length; i++)
                newPercentages.push(Math.random())
            percentages = newPercentages
        }
    }
}
