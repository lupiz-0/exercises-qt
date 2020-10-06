import QtQuick 2.0

MouseArea {
    id: root

    signal back

    width: 80
    height: 80
    hoverEnabled: true
    onClicked: back()

    Image {
        anchors.fill: parent
        source: "images/btn-back-active.svg"
        opacity: root.containsMouse ? 0.5 : 1.0

        Behavior on opacity {
            NumberAnimation {
                duration: clockManager.timeOfTheDissolveAnimation
            }
        }
    }
}
