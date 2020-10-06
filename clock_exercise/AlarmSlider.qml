import QtQuick 2.0
import QtQuick.Controls 2.15

Slider {
    id: root

    property int timeExpressedInMinutes: Math.round(value) % minutesInADay
    property int hours: timeExpressedInMinutes / clockManager.minutesInOneHour
    property int minutes: timeExpressedInMinutes % clockManager.minutesInOneHour
    readonly property int startingHour: 6
    readonly property int minutesInADay: clockManager.hoursInADay * clockManager.minutesInOneHour

    value: 0.5
    from: startingHour * clockManager.minutesInOneHour
    to: (clockManager.hoursInADay + startingHour)*clockManager.minutesInOneHour

    background: Image {
            id: background

            source: "images/comp-slider.svg"
            width: 504
            height: 74
        }

    handle: Item {
        id: handle

        readonly property int horizontalAdjust: 8

        width: 52*2.1 // original size of the image multiplied for a scale factor ( with original size it differs from mockup and is not possible obtain size from mockup )
        height: 57*2.1 // original size  of the image multiplied for a scale factor ( with original size it differs from mockup and is not possible obtain size from mockup )
        x: root.leftPadding + root.visualPosition * (root.availableWidth - width + horizontalAdjust) - horizontalAdjust/2
        y: 7

        Image {
            anchors.fill: parent
            source: "images/handle-enable.svg"
            opacity: root.pressed? 0:1

            Behavior on opacity {
                NumberAnimation { duration: clockManager.timeOfTheDissolveAnimation }
            }

        }

        Image {
            anchors.fill: parent
            source: "images/handle-pressed.svg"
            opacity: root.pressed? 1:0

            Behavior on opacity {
                NumberAnimation { duration: clockManager.timeOfTheDissolveAnimation }
            }

        }
    }

    Text {

        readonly property int yDistanceFromHandle: 23

        x: handle.x - width/2 + handle.width/2
        y: handle.y - yDistanceFromHandle
        width: 200
        text: hours.toString().padStart(2, '0') + ":" + minutes.toString().padStart(2, '0')
        color: "#00B49D"
        font.pixelSize: 24
        horizontalAlignment: Text.AlignHCenter
        font.family: "Buenos Aires"
        font.styleName: "Regular"
    }
}
