import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 800
    visible: true
    title: qsTr("Chapters exercise")

    Column {
        id: allChapters

        property int selectedChapter: -1

        function clickChapter(idNewChapter) {
            if(selectedChapter === idNewChapter)
                selectedChapter = -1
            else
                selectedChapter = idNewChapter
        }

        anchors.centerIn: parent

        Chapter {
            id: chapter0

            titleText: "title 0"
            contentText: "Quel ramo del lago di Como, che volge a mezzogiorno, tra due catene non interrotte di monti, tutto a seni e a golfi, a seconda"
            onClickChapter: allChapters.clickChapter(idNewChapter)
            uniqueIdentifier: 0
            selectedChapter: allChapters.selectedChapter
            othersChaptersPermitOpening: chapter1.permitOpeningOfAnotherChapter && chapter2.permitOpeningOfAnotherChapter
        }

        Chapter {
            id: chapter1

            titleText: "title 1"
            contentText: "dello sporgere e del rientrare di quelli, vien quasi a un tratto, tra un promontorio a destra e un'ampia"
            onClickChapter: allChapters.clickChapter(idNewChapter)
            uniqueIdentifier: 1
            selectedChapter: allChapters.selectedChapter
            othersChaptersPermitOpening: chapter0.permitOpeningOfAnotherChapter && chapter2.permitOpeningOfAnotherChapter
        }

        Chapter {
            id: chapter2

            titleText: "title 2"
            contentText: "costiera dall'altra parte"
            onClickChapter: allChapters.clickChapter(idNewChapter)
            uniqueIdentifier: 2
            selectedChapter: allChapters.selectedChapter
            othersChaptersPermitOpening: chapter0.permitOpeningOfAnotherChapter && chapter1.permitOpeningOfAnotherChapter
        }
    }
}
