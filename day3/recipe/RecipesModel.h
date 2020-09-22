#ifndef RECIPESMODEL_H
#define RECIPESMODEL_H

#include <QtCore>
#include <QtGui>

enum DifficultyLevel {
    Low,
    Mid,
    High
};


struct RecipeData {
    RecipeData(QString descr, QString  imageSo, DifficultyLevel difficul, int prepTime): description(descr), imageSource(imageSo), difficulty(difficul), preparationTime(prepTime){}

    QString  description;
    QString  imageSource;
    DifficultyLevel difficulty;
    int preparationTime;
};

class RecipesModel : public QAbstractListModel
{
    Q_OBJECT
public:


    enum RoleNames {
        DescriptionRole = Qt::UserRole,
        ImageSourceRole = Qt::UserRole + 1,
        DifficultyRole = Qt::UserRole + 2,
        PreparationTimeRole = Qt::UserRole + 3,
        DifficultyStringRole = Qt::UserRole + 4
    };



    explicit RecipesModel(QObject *parent = 0);
    ~RecipesModel();

public: // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    static QString difficultyLevelToString(DifficultyLevel difficultyLevel);

    QList<QSharedPointer<RecipeData>> m_data;
    static const QHash<int, QByteArray> m_roleNames;
};


#endif // RECIPESMODEL_H
