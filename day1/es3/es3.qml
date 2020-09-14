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
//        property bool areAllCompressed: selectedChapter != chapter0.uniqueIdentifier && chapter0.uniqueIdentifier !== selectedChapter
//                                        && selectedChapter != chapter1.uniqueIdentifier && chapter1.uniqueIdentifier !== selectedChapter
//                                        && selectedChapter != chapter1.uniqueIdentifier && chapter2.uniqueIdentifier !== selectedChapter

        function clickChapter(idNewChapter) {
            if(selectedChapter === idNewChapter)
                selectedChapter = -1
            else
                selectedChapter = idNewChapter
        }

        /*
        function changeChapterOld(clickedChapter){

            var otherChapters = [] // all the chapters different from the clicked chapter
            var chapterExpanded = undefined // here we set the chapter expanded ( if is present one )

            for(var i = 0; i < allChapters.children.length; i++) {

                if(allChapters.children[i].id === clickedChapter.id && allChapters.children[i] !== clickedChapter)
                    otherChapters.push(allChapters.children[i]) // collect all the chapters different from the clicked

                if(allChapters.children[i].isExpanded)
                    chapterExpanded = allChapters.children[i]
            }

            if(clickedChapter.isExpanded === true)
                clickedChapter.isExpanded = false // if the chapter clicked is expanded the simply set to close
            else {

                // set all the chapters not clicked to be closed
                for(var j = 0; j < otherChapters.length; j++)
                    otherChapters[j].isExpanded = false

                // if nobody else chapter is expanded now then set immediately to expand the clicked chapter, else expande with a delay
                if(chapterExpanded === undefined)
                    clickedChapter.isExpanded = true
                else {
                    timerForDelayOpeningChapter.chapter = clickedChapter
                    timerForDelayOpeningChapter.start()
                }
            }
        }
        */

        anchors.centerIn: parent

        /*
        Timer {
            id: timerForDelayOpeningChapter

            property var chapter: undefined

            interval: firstChapter.animationTime

            onTriggered: {
                chapter.isExpanded = true
            }
        } 
        */    

        Chapter {
            id: chapter0

            titleText: "title 0"
            contentText: "Quel ramo del lago di Como, che volge a mezzogiorno, tra due catene non interrotte di monti, tutto a seni e a golfi, a seconda"
            onClickChapter: allChapters.clickChapter(idNewChapter)
            uniqueIdentifier: 0
            selectedChapter: allChapters.selectedChapter
            othersCompressed: chapter1.permitOpeningOfAnotherChapter && chapter2.permitOpeningOfAnotherChapter
            //areAllCompressed: allChapters.areAllCompressed
        }

        Chapter {
            id: chapter1

            titleText: "title 1"
            contentText: "dello sporgere e del rientrare di quelli, vien quasi a un tratto, tra un promontorio a destra e un'ampia"
            onClickChapter: allChapters.clickChapter(idNewChapter)
            uniqueIdentifier: 1
            selectedChapter: allChapters.selectedChapter
            othersCompressed: chapter0.permitOpeningOfAnotherChapter && chapter2.permitOpeningOfAnotherChapter
            //areAllCompressed: allChapters.areAllCompressed
        }

        Chapter {
            id: chapter2

            titleText: "title 2"
            contentText: "costiera dall'altra parte"
            onClickChapter: allChapters.clickChapter(idNewChapter)
            uniqueIdentifier: 2
            selectedChapter: allChapters.selectedChapter
            othersCompressed: chapter0.permitOpeningOfAnotherChapter && chapter1.permitOpeningOfAnotherChapter
            //areAllCompressed: allChapters.areAllCompressed
        }

        Timer {
            interval: 500; running: true; repeat: true
            onTriggered: console.log(chapter1.state, " ", chapter1.othersCompressed)
        }
    }
}
