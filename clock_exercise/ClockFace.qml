import QtQuick 2.0

Rectangle {
    id: clockFace

    readonly property real amountMinutesInClockFace: 60
    readonly property real clockHandImageAdaptationAngle: 90
    readonly property real amountHoursInClockFace: 12
    readonly property real angleOfOneHour: 360/amountHoursInClockFace
    readonly property real angleOfOneMinute: 360/amountMinutesInClockFace
    readonly property real angleOfOneMinuteForHourClockHand: 360/(amountMinutesInClockFace*amountHoursInClockFace)

    width: 418
    height: 418
    color: "#1B2F46"
    radius: width*0.5

    Image {

        width: 375
        height: width
        source: "images/comp_tic-tac.svg"
        anchors.centerIn: parent

        Image {
            id: hourHand

            x: parent.width/2 - height/2
            y: parent.height/2 - height/2
            width: 110
            height: 11
            source: "images/ic-clock-hand_hours.svg"

            transform: Rotation{
                id: hourHandRotation

                origin.x: hourHand.height/2
                origin.y: hourHand.height/2
                angle: {
                    var ang = clockManager.hours % clockFace.amountHoursInClockFace
                    ang = ang*angleOfOneHour + clockManager.minutes*clockFace.angleOfOneMinuteForHourClockHand - clockFace.clockHandImageAdaptationAngle
                }

                Behavior on angle {
                    NumberAnimation { duration: clockManager.timeOfTheDissolveAnimation }
                }
            }
        }

        Image {
            id: minuteHand

            x: parent.width/2 - height/2
            y: parent.height/2 - height/2
            width: 130
            height: 8
            source: "images/ic-clock-hand_hours.svg"

            transform: Rotation{
                id: minuteHandRotation

                origin.x: minuteHand.height/2
                origin.y: minuteHand.height/2
                angle: clockManager.minutes*clockFace.angleOfOneMinute - clockFace.clockHandImageAdaptationAngle

                Behavior on angle {
                    NumberAnimation { duration: clockManager.timeOfTheDissolveAnimation }
                }
            }
        }

        Image {
            id: clockHandsCenter

            width: 22
            height: width
            source: "images/ic-clock-hands_center.svg"
            anchors.centerIn: parent
        }
    }
}
