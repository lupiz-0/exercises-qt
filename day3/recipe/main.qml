import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.15

Window {
    id: mainWindow

    width: 500
    height: 400
    title: qsTr("Recipe exercise")

    ListModel {
        id: recipesModel
        ListElement {
            imageSource: "images/carote_latte.jpg"
            description:  qsTr("Carote al latte")
            difficulty: Recipe.Difficulty.High
            preparationTime: 20
        }
        ListElement {
            imageSource: "images/lasagne_asparagi.jpg"
            description:  qsTr("Lasagne asparagi e raspadura")
            difficulty: Recipe.Difficulty.Mid
            preparationTime: 60
        }
        ListElement {
            imageSource: "images/orata_forno.jpg"
            description:  qsTr("Orata al forno")
            difficulty: Recipe.Difficulty.Low
            preparationTime: 50
        }
        ListElement {
            imageSource: "images/penne_ragu_verdura.jpg"
            description:  qsTr("Penne al ragù di verdura")
            difficulty: Recipe.Difficulty.High
            preparationTime: 20
        }
        ListElement {
            imageSource: "images/zucca_allo_zenzero.jpg"
            description:  qsTr("Zucca allo zenzero")
            difficulty: Recipe.Difficulty.Mid
            preparationTime: 40
        }
    }

    Component {
        id: recipesListView

        ListView {
            model: recipesModel
            delegate: RecipeSlot {
                color: index%2 === 0? "lightslategrey": "lightgrey"
                width: ListView.view.width
                onPushRecipePage: {
                    stack.push(recipePage, {"title": description, "imageSource": imageSource, "difficultyId": difficulty, "preparationTime": preparationTime})
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
