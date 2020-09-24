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
        RecipeData(const QString& description, const QString& imageSource, DifficultyLevel difficulty, int preparationTime, bool preferred): m_description(description)
            , m_imageSource(imageSource), m_difficulty(difficulty)
            , m_preparationTime(preparationTime), m_preferred(preferred) {}

        QString  m_description;
        QString  m_imageSource;
        DifficultyLevel m_difficulty;
        int m_preparationTime;
        bool m_preferred;
    };

    explicit RecipesModel(QObject *parent = 0);
    ~RecipesModel() = default;

public: // QAbstractItemModel interface
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    QVector<RecipeData> m_data = {  RecipeData("Carote al latte", "images/carote_latte.jpg", DifficultyLevel::HighDifficulty, 10, false)
                                    , RecipeData("Lasagne asparagi e raspadura", "images/lasagne_asparagi.jpg", DifficultyLevel::MidDifficulty, 20, false)
                                    , RecipeData("Orata al forno", "images/orata_forno.jpg", DifficultyLevel::LowDifficulty, 30, false)
                                    , RecipeData("Penne al ragù di verdura", "images/penne_ragu_verdura.jpg", DifficultyLevel::HighDifficulty, 40, false)
                                    , RecipeData("Zucca allo zenzero", "images/zucca_allo_zenzero.jpg", DifficultyLevel::MidDifficulty, 50, false)};
    static const QHash<int, QByteArray> m_roleNames;
};


#endif // RECIPESMODEL_H
