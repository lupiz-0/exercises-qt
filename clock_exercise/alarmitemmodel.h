#pragma once

#include <QAbstractListModel>
#include "alarmitemdata.h"

class AlarmItemModel : public QAbstractListModel
{
    Q_OBJECT

    Q_PROPERTY(bool atLeastOneEverydayAlarm MEMBER m_atLeastOneEverydayAlarm NOTIFY atLeastOneEverydayAlarmChanged WRITE setAtLeastOneEverydayAlarm)
    Q_PROPERTY(int numberSelectedAlarms MEMBER m_numberSelectedAlarms NOTIFY numberSelectedAlarmsChanged WRITE setNumberSelectedAlarms)
    Q_PROPERTY(int dataCount MEMBER m_dataCount NOTIFY dataCountChanged WRITE setDataCount)
    
    bool m_atLeastOneEverydayAlarm;
    int m_numberSelectedAlarms;
    int m_dataCount;

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
    void setAtLeastOneEverydayAlarm(bool atLeastOneEverydayAlarm);
    void setNumberSelectedAlarms(int numberSelectedAlarms);
    void setDataCount(int dataCount);

public slots:
    void addNewAlarm(AlarmItemData alarm);
    AlarmItemData newAlarmItemData(){return AlarmItemData();}
    void setAllNotSelected();
    void deleteSelectedAlarms();

signals:
    void atLeastOneEverydayAlarmChanged();
    void numberSelectedAlarmsChanged();
    void dataCountChanged();

protected:
    QHash<int, QByteArray> roleNames() const override;

private slots:

private:

};

Q_DECLARE_METATYPE(AlarmItemModel*)

