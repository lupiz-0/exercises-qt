import QtQuick 2.0

Image {
    id: root

    property alias angle: rotation.angle

    width: 6
    height: 134
    source: "images/ic-clock-hand_mins.svg"

    transform: Rotation{
        id: rotation

        origin.x: root.width/2
        origin.y: root.width/2

        Behavior on angle {
            RotationAnimation { duration: clockManager.timeOfTheDissolveAnimation; direction: RotationAnimation.Clockwise }
        }
    }
}
