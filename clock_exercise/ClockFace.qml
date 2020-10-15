import QtQuick 2.0

Rectangle {
    id: clockFace

    property alias alarmClockHandVisible: alarmClockHand.visible
    property int alarmHours
    property int alarmMinutes
    property real scaledWidth //if 0 not scale, else set a scale to reach this value on width (see "transform: Scale {" in this page)
    property real scaledHeight //if 0 not scale, else set a scale to reach this value on height (see "transform: Scale {" in this page)
    readonly property real clockHandHoursImageAdaptationAngle: -90
    readonly property real clockHandMinutesImageAdaptationAngle: 180
    readonly property real clockHandAlarmImageAdaptationAngle: 180
    readonly property real amountHoursInClockFace: 12
    readonly property real angleOfOneHour: 360/amountHoursInClockFace
    readonly property real angleOfOneMinute: 360/60
    readonly property real angleOfOneMinuteForHourClockHand: 360.0/(60 * amountHoursInClockFace)

    function angleFromHoursAndMinutes(hours, minutes, adaptationAngle) {
        var ang = hours % clockFace.amountHoursInClockFace
        return ang * clockFace.angleOfOneHour + minutes * clockFace.angleOfOneMinuteForHourClockHand + adaptationAngle
    }

    width: 418
    height: 418
    color: "#1B2F46"
    radius: width*0.5

    transform: Scale {
        xScale: clockFace.scaledWidth === 0? 1: clockFace.scaledWidth / clockFace.width
        yScale: clockFace.scaledHeight === 0? 1: clockFace.scaledHeight / clockFace.height
    }

    Image {

        width: 375
        height: 375
        source: "images/comp_tic-tac.svg"
        anchors.centerIn: parent

        AlarmClockHand {
            id: alarmClockHand

            x: parent.width/2 - width/2
            y: parent.height/2 - width/2
            angle: angleFromHoursAndMinutes(clockFace.alarmHours, clockFace.alarmMinutes, clockFace.clockHandAlarmImageAdaptationAngle)
        }

        HoursClockHand {
            x: parent.width/2 - height/2
            y: parent.height/2 - height/2
            angle: angleFromHoursAndMinutes(clockManager.hours, clockManager.minutes, clockFace.clockHandHoursImageAdaptationAngle)
        }

        MinuteClockHand {
            x: parent.width/2 - width/2
            y: parent.height/2 - width/2
            angle: clockManager.minutes*clockFace.angleOfOneMinute + clockFace.clockHandMinutesImageAdaptationAngle
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
