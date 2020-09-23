#include "RecipesModel.h"

const QHash<int, QByteArray> RecipesModel::m_roleNames {
    {DescriptionRole, "description"}, {ImageSourceRole, "imageSource"}, {DifficultyRole, "difficulty"}, {PreparationTimeRole, "preparationTime"}
    , {DifficultyStringRole, "difficultyString"}, {PreferredRole, "preferred"}
};

const QString RecipesModel::difficultyStrings[DifficultyCount]{
    "Bassa",
    "Media",
    "Alta"
};

RecipesModel::RecipesModel(QObject *parent)
    : QAbstractListModel(parent)
{
    m_data.append(std::make_shared<RecipeData>("Carote al latte", "images/carote_latte.jpg", DifficultyLevel::HighDifficulty, 10, false));
    m_data.append(std::make_shared<RecipeData>("Lasagne asparagi e raspadura", "images/lasagne_asparagi.jpg", DifficultyLevel::MidDifficulty, 20, false));
    m_data.append(std::make_shared<RecipeData>("Orata al forno", "images/orata_forno.jpg", DifficultyLevel::LowDifficulty, 30, false));
    m_data.append(std::make_shared<RecipeData>("Penne al ragù di verdura", "images/penne_ragu_verdura.jpg", DifficultyLevel::HighDifficulty, 40, false));
    m_data.append(std::make_shared<RecipeData>("Zucca allo zenzero", "images/zucca_allo_zenzero.jpg", DifficultyLevel::MidDifficulty, 50, false));
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
        case PreferredRole:
            return m_data.value(row)->preferred;
    }

    return QVariant();
}

QHash<int, QByteArray> RecipesModel::roleNames() const
{
    return m_roleNames;
}

bool RecipesModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    int row = index.row();
    if(row < 0 || row >= m_data.count()) {
        return false;
    }

    switch (role) {
    case PreferredRole:
        if (value != m_data.value(row)->preferred) {
            m_data.value(row)->preferred = value.toBool();
            emit dataChanged(index, index);
            return true;
        }
        break;
    }

    return false;
}

Qt::ItemFlags RecipesModel::flags(const QModelIndex& index) const
{
    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}
