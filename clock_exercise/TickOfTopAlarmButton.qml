import QtQuick 2.0

Item {

    property bool visualizationOfSelected
    property bool visualizationOfHover

    x: 20; y:8
    width: 34
    height: 34

    Image {
        opacity: (visualizationOfSelected && !visualizationOfHover || !visualizationOfSelected && visualizationOfHover)? 1:0
        source: "images/ic-tick-selected.svg"

        Behavior on opacity {
            NumberAnimation {
                duration: button.timeOfDissolve
            }
        }
    }

    Image {
        opacity: (visualizationOfSelected && visualizationOfHover)? 1:0
        source: "images/ic-tick-hover.svg"

        Behavior on opacity {
            NumberAnimation {
                duration: button.timeOfDissolve
            }
        }
    }

    Image {
        opacity: (!visualizationOfSelected && !visualizationOfHover)? 1:0
        source: "images/ic-tick-disabled.svg"

        Behavior on opacity {
            NumberAnimation {
                duration: button.timeOfDissolve
            }
        }
    }
}
