import QtQuick 2.0
import QtQuick.Shapes 1.15

Rectangle {
    id: clockPage

    property int timeOfDissolve: 500

    signal timerButtonClicked
    signal alarmButtonClicked

    color: "#151B2E"

    FontLoader {
        id: buenosAiresRegular;
        source: "fonts/BuenosAires_Family/BuenosAires-Regular.otf"
    }

    FontLoader {
        id: buenosAiresSemiBold;
        source: "fonts/BuenosAires_Family/BuenosAires-SemiBold.otf"
    }

    Text {
        x: 162
        y: 40
        width: 156
        height: 36
        text: "DeveClock"
        color: "#9FAAB0"
        font.pixelSize: 30
        horizontalAlignment: Text.AlignHCenter
        font.family: buenosAiresSemiBold.name
        font.styleName: "SemiBold"
    }

    Text {
        x: 360
        y: 42
        width: 50
        height: 50
        text: "T"
        font.pixelSize: 26
        horizontalAlignment: Text.AlignHCenter
        font.family: buenosAiresSemiBold.name
        font.styleName: "SemiBold"
        color: "#EC6545"
    }

    Image {
        x: 405
        y: 35
        width: 50
        height: 50
        source: "images/switch-on-disable.svg"
    }

    Rectangle {
        x: 31
        y: 110
        width: 418
        height: 1
        color: "#9FAAB0"
    }



    Text {
        x: 122
        y: 153
        width: 236
        height: 29
        text: clockManager !== null? clockManager.dateText: ""
        color: "#FCB647"
        font.pixelSize: 24
        horizontalAlignment: Text.AlignHCenter
        font.capitalization: Font.Capitalize
        font.family: buenosAiresRegular.name
        font.styleName: "Regular"
    }

    Rectangle {
        id: clockFaceBackground

        x: 31
        y: 220
        width: 418
        height: width
        color: "#1B2F46"
        radius: width*0.5

        Image {
            id: clockFace

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

                    angle: clockManager !== null? clockManager.hoursClockHandAngle: 0
                    origin.x: hourHand.height/2
                    origin.y: hourHand.height/2
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

                    angle: clockManager !== null? clockManager.minutesClockHandAngle: 0
                    origin.x: minuteHand.height/2
                    origin.y: minuteHand.height/2
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

    Rectangle {
        id: timerButton

        x: 18
        y: 690
        width: 190
        height: 64
        color: timerButtonMouseArea.containsMouse? "#FCB647": "#151B2E"
        border.color : "#FCB647"
        border.width : 1
        radius: 32

        Behavior on color {
            ColorAnimation {
                duration: timeOfDissolve
            }
        }

        Text {
            id: timerButtonText

            width: 96
            height: 36
            text: "TIMER"
            color: timerButtonMouseArea.containsMouse? "#151B2E": "#FCB647"
            anchors.centerIn: parent
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            font.family: buenosAiresSemiBold.name
            font.styleName: "SemiBold"

            Behavior on color {
                ColorAnimation {
                    duration: timeOfDissolve
                }
            }

        }

        MouseArea {
            id: timerButtonMouseArea

            hoverEnabled: true
            anchors.fill: parent
            onClicked: clockPage.timerButtonClicked()
        }
    }

    Rectangle {
        id: alarmButton

        x: 272
        y: 690
        width: 190
        height: 64
        color: alarmButtonMouseArea.containsMouse? "#FCB647": "#151B2E"
        border.color : "#FCB647"
        border.width : 1
        radius: 32

        Behavior on color {
            ColorAnimation {
                duration: timeOfDissolve
            }
        }

        Text {
            id: alarmButtonText

            width: 96
            height: 36
            text: "ALARM"
            color: alarmButtonMouseArea.containsMouse? "#151B2E": "#FCB647"
            anchors.centerIn: parent
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            font.family: buenosAiresSemiBold.name
            font.styleName: "SemiBold"

            Behavior on color {
                ColorAnimation {
                    duration: timeOfDissolve
                }
            }
        }

        MouseArea {
            id: alarmButtonMouseArea

            hoverEnabled: true
            anchors.fill: parent
            onClicked: clockPage.alarmButtonClicked()
        }
    }
}
