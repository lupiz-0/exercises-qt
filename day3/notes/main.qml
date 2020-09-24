import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.15

Window {
    id: mainWindow

    width: 640
    height: 480    
    title: qsTr("Notes")
    visible: true

    Column {
        Rectangle {
            id: windowArea


            function printCards() {
                console.log("print cards:");
                for(var i = 0; i < noteModel.count; i++) {
                    var noteItem = noteModel.getUsingInternalArrayId(i)
                    var message = "   card: id(%1), x(%2), y(%3), text(%4)"
                    console.log(message.arg(noteItem.id).arg(noteItem.x).arg(noteItem.y).arg(noteItem.text))
                }
            }

            function createCard(text) {
                var newObjectCreated  = cardComponent.createObject(windowArea, {"text": text})
                newObjectCreated.uniqueId = noteModel.getFreeUniqueId()
                newObjectCreated.x = Math.random()*(windowArea.width - newObjectCreated.width)
                newObjectCreated.y = Math.random()*(windowArea.height - newObjectCreated.height)
                newObjectCreated.drag.maximumX = Qt.binding(function(){ return windowArea.width - newObjectCreated.width })
                newObjectCreated.drag.maximumY = Qt.binding(function(){ return windowArea.height - newObjectCreated.height })

                var noteItem = noteModel.newNoteItem(newObjectCreated.uniqueId, newObjectCreated.x, newObjectCreated.y, text);
                noteModel.addNote(noteItem)
                printCards();
            }

            width: mainWindow.width
            height: mainWindow.height - barCreationNewCard.height
            Component.onCompleted: {
                windowArea.createCard("Quel ramo del lago di Como, che volge a mezzogiorno, tra due catene non interrotte di monti, tutto a seni e a golfi, a seconda dello sporgere e del rientrare di quelli, vien quasi a un tratto, tra un promontorio a destra e un'ampia costiera dall'altra parte")
            }

            Component {
                id: cardComponent
                Card {
                    onPrintCards: windowArea.printCards()
                }
            }
        }

        BarCreationNewCard {
            id: barCreationNewCard

            width: mainWindow.width
            onCreateCardButtonClicked: windowArea.createCard(text)
        }
    }
}
