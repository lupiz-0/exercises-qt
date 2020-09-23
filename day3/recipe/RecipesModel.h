#ifndef RECIPESMODEL_H
#define RECIPESMODEL_H

#include <QtCore>
#include <QtGui>
#include <memory>


class RecipesModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum DifficultyLevel {
        LowDifficulty,
        MidDifficulty,
        HighDifficulty,
        DifficultyCount,
    };
    Q_ENUM(DifficultyLevel)

    static const QString difficultyStrings[];

    enum RoleNames {
        DescriptionRole = Qt::UserRole,
        ImageSourceRole = Qt::UserRole + 1,
        DifficultyRole = Qt::UserRole + 2,
        PreparationTimeRole = Qt::UserRole + 3,
        DifficultyStringRole = Qt::UserRole + 4,
        PreferredRole = Qt::UserRole + 5
    };

    struct RecipeData {
        RecipeData(QString descr, QString  imageSo, DifficultyLevel difficul, int prepTime, bool pref): description(descr), imageSource(imageSo), difficulty(difficul)
            , preparationTime(prepTime), preferred(pref){}

        QString  description;
        QString  imageSource;
        DifficultyLevel difficulty;
        int preparationTime;
        bool preferred;
    };

    explicit RecipesModel(QObject *parent = 0);
    ~RecipesModel();

public: // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    QList<std::shared_ptr<RecipeData>> m_data;
    static const QHash<int, QByteArray> m_roleNames;
};


#endif // RECIPESMODEL_H
