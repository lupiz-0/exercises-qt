import QtQuick 2.0

Image {
    id: root

    property alias angle: rotation.angle

    width: 111
    height: 12
    source: "images/ic-clock-hand_hours.svg"

    transform: Rotation{
        id: rotation

        origin.x: root.height/2
        origin.y: root.height/2

        Behavior on angle {
            NumberAnimation { duration: 500 }
        }
    }
}
