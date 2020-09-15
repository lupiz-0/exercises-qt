import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: mainWindow

    property var cardPrefab: Qt.createComponent("Card.qml");

    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    function createCard() {
        while (mainWindow.cardPrefab.status !== Component.Ready){ }
        mainWindow.cardPrefab.createObject(
                    mainWindow, {
                        "x": Math.random()*mainWindow.width
                        , "y": Math.random()*mainWindow.height
                        , "widthParent": mainWindow.width
                        , "heightParent": mainWindow.height
                    }
            )
    }

    property int widthParent
    property int heightParent

    Component.onCompleted: {
        for(var i = 0; i < 10; i++) {
            mainWindow.createCard()
      }
    }

    /*
    Card {
        x: 0
        y: 0
    }
    Card {
        x: 200
        y: 200
    }
    */
}
