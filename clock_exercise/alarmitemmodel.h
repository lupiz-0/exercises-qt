#pragma once

#include <QAbstractListModel>
#include "alarmitemdata.h"
#include <QDate>

class AlarmItemModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(int numberEverydayAlarms MEMBER m_numberEverydayAlarms NOTIFY numberEverydayAlarmsChanged)
    Q_PROPERTY(int numberSelectedAlarms MEMBER m_numberSelectedAlarms NOTIFY numberSelectedAlarmsChanged)
    Q_PROPERTY(int dataCount MEMBER m_dataCount NOTIFY dataCountChanged)
    Q_PROPERTY(int numberActiveAlarms MEMBER m_numberActiveAlarms NOTIFY numberActiveAlarmsChanged)
    
    int m_numberEverydayAlarms;
    int m_numberSelectedAlarms;
    int m_dataCount;
    int m_numberActiveAlarms;

    QVector<AlarmItemData> m_data;
    static const QHash<int, QByteArray> m_roleNames;

public:
    AlarmItemModel();

    enum RoleNames {
        ActiveRole = Qt::UserRole,
        SelectedRole = Qt::UserRole + 1,
        DayRole = Qt::UserRole + 2,
        MonthRole = Qt::UserRole + 3,
        YearRole = Qt::UserRole + 4,
        HoursRole = Qt::UserRole + 5,
        MinutesRole = Qt::UserRole + 6,
        EverydayRole = Qt::UserRole + 7
    };

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

public slots:
    void addNewAlarm(bool everyDay, QDate date, int hours, int minutes);
    void setAllNotSelected();
    void deleteSelectedAlarms();

signals:
    void numberEverydayAlarmsChanged();
    void numberSelectedAlarmsChanged();
    void dataCountChanged();
    void numberActiveAlarmsChanged();

protected:
    QHash<int, QByteArray> roleNames() const override;

private slots:

private:
    void setNumberEverydayAlarms(int numberEverydayAlarms);
    void setNumberSelectedAlarms(int numberSelectedAlarms);
    void setDataCount(int dataCount);
    void setNumberActiveAlarms(int numberActiveAlarms);
};

Q_DECLARE_METATYPE(AlarmItemModel*)

