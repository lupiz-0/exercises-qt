import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15
import org.example 1.0

Window {
    id: mainWindow

    width: 500
    height: 400
    title: qsTr("Recipe exercise")
    visible: true
    minimumWidth: 250

    Component {
        id: recipesListView

        ListView {
            model: RecipesModel {}
            delegate: RecipeSlot {
                color: index%2 === 0? "lightslategrey": "lightgrey"
                width: ListView.view.width
                onPushRecipePage: {
                    stack.push(recipePage, {"title": description, "imageSource": imageSource, "difficultyString": difficultyString, "preparationTime": preparationTime}, {"preferred": preferred})
                }
            }
        }
    }

    Component {
        id: recipePage
        RecipePage {
            onBack: stack.pop()
        }
    }

    StackView {
        id: stack
        initialItem: recipesListView
        anchors.fill: parent
    }
}
