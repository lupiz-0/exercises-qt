import QtQuick 2.0



MouseArea {
    id: card

    property int widthParent
    property int heightParent
   // property bool outOfArea: x + width > widthParent || y + height > heightParent

    //drag.target: (x + width > widthParent) || (y + height > heightParent)? undefined: this
//    x: (x + width > widthParent)? (widthParent - width): x
//    y: (y + height > heightParent)? (heightParent - height): y
    //x: (x + width > widthParent)? 100: x
    //y: (y + height > heightParent)? 100: y
    width: 150
    height: topBar.height + contentArea.height
    drag.target: this
    drag.minimumX: 0
    drag.minimumY: 0
    drag.maximumX: widthParent - width
    drag.maximumY: heightParent - height



    onClicked: {
        console.log("click!!!")
    }

    /*
    onOutOfAreaChanged: {
        drag.target = undefined
        if(outOfArea) {
            if(x + width > widthParent)
                x = widthParent - width
            if(y + height > heightParent)
                y = heightParent - height
        }
        drag.target = this
    }
    */

    Column {
        Rectangle {
            id: topBar

            color: "green"
            width: card.width
            height: 30
        }

        Rectangle {
            id: contentArea

            color: "yellow"
            width: card.width
            height: 105
        }
    }
}
