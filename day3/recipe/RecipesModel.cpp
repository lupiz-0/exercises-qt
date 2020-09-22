#include "RecipesModel.h"

const QHash<int, QByteArray> RecipesModel::m_roleNames {
    {DescriptionRole, "description"}, {ImageSourceRole, "imageSource"}, {DifficultyRole, "difficulty"}, {PreparationTimeRole, "preparationTime"}, {DifficultyStringRole, "difficultyString"}
};

const QString RecipesModel::difficultyStrings[DifficultyCount]{
    "Bassa",
    "Media",
    "Alta"
};

RecipesModel::RecipesModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_data.append(std::make_shared<RecipeData>("Carote al latte", "images/carote_latte.jpg", DifficultyLevel::HighDifficulty, 10));
    m_data.append(std::make_shared<RecipeData>("Lasagne asparagi e raspadura", "images/lasagne_asparagi.jpg", DifficultyLevel::MidDifficulty, 20));
    m_data.append(std::make_shared<RecipeData>("Orata al forno", "images/orata_forno.jpg", DifficultyLevel::LowDifficulty, 30));
    m_data.append(std::make_shared<RecipeData>("Penne al ragù di verdura", "images/penne_ragu_verdura.jpg", DifficultyLevel::HighDifficulty, 40));
    m_data.append(std::make_shared<RecipeData>("Zucca allo zenzero", "images/zucca_allo_zenzero.jpg", DifficultyLevel::MidDifficulty, 50));
}

RecipesModel::~RecipesModel()
{
}

int RecipesModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
            return 0;
    return m_data.count();
}

QVariant RecipesModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row < 0 || row >= m_data.count()) {
        return QVariant();
    }

    switch(role) {
        case DescriptionRole:
            return m_data.value(row)->description;
        case ImageSourceRole:
            return m_data.value(row)->imageSource;
        case DifficultyRole:
            return m_data.value(row)->difficulty;
        case PreparationTimeRole:
            return m_data.value(row)->preparationTime;
        case DifficultyStringRole:
            return difficultyStrings[m_data.value(row)->difficulty];
    }

    return QVariant();
}

QHash<int, QByteArray> RecipesModel::roleNames() const
{
    return m_roleNames;
}
