import QtQuick 2.0

Item {
    id: root

    property bool visualizationOfSelected
    property bool visualizationOfHover

    width: 34
    height: 34

    Image {
        opacity: (root.visualizationOfSelected && !root.visualizationOfHover)
                 || (!root.visualizationOfSelected && root.visualizationOfHover)
        source: "images/ic-tick-selected.svg"

        Behavior on opacity {
            NumberAnimation {
                duration: clockManager.timeOfTheDissolveAnimation
            }
        }
    }

    Image {
        opacity: root.visualizationOfSelected && root.visualizationOfHover
        source: "images/ic-tick-hover.svg"

        Behavior on opacity {
            NumberAnimation {
                duration: clockManager.timeOfTheDissolveAnimation
            }
        }
    }

    Image {
        opacity: !root.visualizationOfSelected && !root.visualizationOfHover
        source: "images/ic-tick-disabled.svg"

        Behavior on opacity {
            NumberAnimation {
                duration: clockManager.timeOfTheDissolveAnimation
            }
        }
    }
}
