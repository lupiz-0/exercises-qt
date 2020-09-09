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

        function changeChapter(){
            console.log("ba ba ba ...")
        }

        Chapter {
            title: "title 0"
            content: "Quel ramo del lago di Como, che volge a mezzogiorno, tra due catene non interrotte di monti, tutto a seni e a golfi, a seconda dello sporgere e del rientrare di quelli ..."
            onClickChapter: allChapters.changeChapter()
        }

        Chapter {
            title: "title 1"
            content: "Quel ramo del lago di Como, che volge a mezzogiorno, tra due catene non interrotte di monti, tutto a seni e a golfi, a seconda dello sporgere e del rientrare di quelli ..."
            onClickChapter: allChapters.changeChapter()
        }

        Chapter {
            title: "title 2"
            content: "Quel ramo del lago di Como, che volge a mezzogiorno, tra due catene non interrotte di monti, tutto a seni e a golfi, a seconda dello sporgere e del rientrare di quelli ..."
            onClickChapter: allChapters.changeChapter()
        }
    }
}
