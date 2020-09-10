import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 800
    visible: true
    title: qsTr("Hello World")




    Column {
        id: allChapters

        anchors.centerIn: parent

        function changeChapter(sender){
            var otherChapters = []
            for(var i = 0; i < allChapters.children.length; i++) {
            //for(var childd in allChapters.children) {
                if(allChapters.children[i].id === sender.id && allChapters.children[i] !== sender)
                    otherChapters.push(allChapters.children[i])
            //    if(childd.id === sender.id && childd !== sender)
            //        otherChapters.push(childd)
            }

            if(sender.isExpanded === true) {
                sender.isExpanded = false
            }
            else {
                for(var j = 0; j < otherChapters.length; j++)
                {
                    otherChapters[j].isExpanded = false
                }
                sender.isExpanded = true
            }

        //    console.log("number other ", otherChapters.length)
        }

        Chapter {
            title: "title 0"
            content: "Quel ramo del lago di Como, che volge a mezzogiorno, tra due catene non interrotte di monti, tutto a seni e a golfi, a seconda dello sporgere e del rientrare di quelli ..."
            onClickChapter: allChapters.changeChapter(sender)
        }

        Chapter {
            title: "title 1"
            content: "Quel ramo del lago di Como, che volge a mezzogiorno, tra due catene non interrotte di monti, tutto a seni e a golfi, a seconda dello sporgere e del rientrare di quelli ..."
            onClickChapter: allChapters.changeChapter(sender)
        }

        Chapter {
            title: "title 2"
            content: "Quel ramo del lago di Como, che volge a mezzogiorno, tra due catene non interrotte di monti, tutto a seni e a golfi, a seconda dello sporgere e del rientrare di quelli ..."
            onClickChapter: allChapters.changeChapter(sender)
        }
    }
}
