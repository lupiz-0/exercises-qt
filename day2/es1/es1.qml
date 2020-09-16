import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.15

Window {
    id: mainWindow

    width: 640
    height: 480    
    title: qsTr("Hello World")

    Column {
        spacing: 0

        Rectangle {
            id: windowArea

            property var cardPrefab: Qt.createComponent("Card.qml");

            function createCard(text) {
                while (windowArea.cardPrefab.status !== Component.Ready){ }
                var newObjectCreated = windowArea.cardPrefab.createObject(windowArea)
                newObjectCreated.x = Math.random()*(windowArea.width - newObjectCreated.width)
                newObjectCreated.y = Math.random()*(windowArea.height - newObjectCreated.height)
                newObjectCreated.drag.maximumX = Qt.binding(function(){ return windowArea.width - newObjectCreated.width })
                newObjectCreated.drag.maximumY = Qt.binding(function(){ return windowArea.height - newObjectCreated.height })
                newObjectCreated.text = text
            }

            visible: true
            width: mainWindow.width
            height: mainWindow.height - barCreationNewCard.height
            Component.onCompleted: {
                windowArea.createCard("Quel ramo del lago di Como, che volge a mezzogiorno, tra due catene non interrotte di monti, tutto a seni e a golfi, a seconda dello sporgere e del rientrare di quelli, vien quasi a un tratto, tra un promontorio a destra e un'ampia costiera dall'altra parte")
            }
        }

        BarCreationNewCard {
            id: barCreationNewCard

            width: mainWindow.width
            onCreateCardButtonClicked: windowArea.createCard(text)
        }
    }
}
