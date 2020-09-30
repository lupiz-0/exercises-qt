import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

Window {
    width: 480
    height: 800
    maximumHeight: height
    maximumWidth: width
    minimumHeight: height
    minimumWidth: width
    visible: true
    title: qsTr("Clock Exercise")

    FontLoader {
        id: buenosAiresRegular;
        source: "fonts/BuenosAires_Family/BuenosAires-Regular.otf"
    }

    FontLoader {
        id: buenosAiresSemiBold;
        source: "fonts/BuenosAires_Family/BuenosAires-SemiBold.otf"
    }

    StackView {
        id: stack
        initialItem: clockPage
        anchors.fill: parent
    }

    Component {
        id: clockPage
        ClockPage {
            onTimerButtonClicked: console.log("timer button clicked")
            onAlarmButtonClicked: console.log("alarm button clicked")
        }
    }
}
