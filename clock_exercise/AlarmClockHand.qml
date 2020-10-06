import QtQuick 2.0

Image {
    id: root

    property alias angle: rotation.angle

    width: 3*1.4 // original size multiplied for a scale factor ( with original size it differs from mockup and is not possible obtain size from mockup )
    height: 116*1.4 // original size multiplied for a scale factor ( with original size it differs from mockup and is not possible obtain size from mockup )
    source: "images/ic-clock-hand-alarm.svg"

    transform: Rotation{
        id: rotation

        origin.x: root.width/2
        origin.y: root.width/2
    }
}
