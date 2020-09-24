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
            return m_data[row].m_description;
        case ImageSourceRole:
            return m_data[row].m_imageSource;
        case DifficultyRole:
            return m_data[row].m_difficulty;
        case PreparationTimeRole:
            return m_data[row].m_preparationTime;
        case DifficultyStringRole:
            return difficultyStrings[m_data[row].m_difficulty];
        case PreferredRole:
            return m_data[row].m_preferred;
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
        if (value != m_data[row].m_preferred) {
            m_data[row].m_preferred = value.toBool();
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
