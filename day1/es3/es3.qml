import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 800
    visible: true
    title: qsTr("Chapters exercise")


    ListView {
        id: allChapters

        property int selectedChapter: -1
        property bool othersChaptersPermitOpening: {
            var permitOpening = true
            for(var i = 0; i < allChapters.count; i++) {
                if(i !== selectedChapter && !allChapters.itemAtIndex(i).permitOpeningOfAnotherChapter)
                    permitOpening = false
            }
            return permitOpening
        }

        function clickChapter(idNewChapter) {
            if(selectedChapter === idNewChapter)
                selectedChapter = -1
            else
                selectedChapter = idNewChapter
        }

        width: 180
        height: 800

        model: ListModel {

            ListElement {
                modelText: "title 0"
                modelContent: "Quel ramo del lago di Como, che volge a mezzogiorno, tra due catene non interrotte di monti, tutto a seni e a golfi, a seconda"
            }
            ListElement {
                modelText: "title 1"
                modelContent: "dello sporgere e del rientrare di quelli, vien quasi a un tratto, tra un promontorio a destra e un'ampia"
            }
            ListElement {
                modelText: "title 2"
                modelContent: "costiera dall'altra parte"
            }
        }

        delegate: Chapter {        
            titleText: modelText
            contentText: modelContent
            onClickChapter: allChapters.clickChapter(idNewChapter)
            selectedChapter: allChapters.selectedChapter
            othersChaptersPermitOpening: allChapters.othersChaptersPermitOpening
        }
    }
}
