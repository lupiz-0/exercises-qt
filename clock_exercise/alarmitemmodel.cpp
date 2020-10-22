#include "alarmitemmodel.h"
#include "notifierofchange.h"

const QHash<int, QByteArray> AlarmItemModel::m_roleNames {
    {EverydayRole, "everyday"}, {ActiveRole, "active"}, {SelectedRole, "selected"}, {DayRole, "day"},  {MonthRole, "month"}, {YearRole, "year"}, {HoursRole, "hours"}, {MinutesRole, "minutes"}
};

AlarmItemModel::AlarmItemModel(): m_numberEverydayAlarms(0), m_numberSelectedAlarms(0), m_dataCount(0), m_numberActiveAlarms(0)
{
}

int AlarmItemModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
            return 0;
    return m_data.count();
}

QVariant AlarmItemModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if(row < 0 || row >= m_data.count()) {
        return QVariant();
    }

    switch(role) {
        case EverydayRole:
            return m_data[row].m_everyday;
        case ActiveRole:
            return m_data[row].m_active;
        case SelectedRole:
            return m_data[row].m_selected;
        case DayRole:
            return m_data[row].m_day;
        case MonthRole:
            return m_data[row].m_month;
        case YearRole:
            return m_data[row].m_year;
        case HoursRole:
            return m_data[row].m_hours;
        case MinutesRole:
            return m_data[row].m_minutes;
    }

    return QVariant();
}

QHash<int, QByteArray> AlarmItemModel::roleNames() const
{
    return m_roleNames;
}

void AlarmItemModel::setAllNotSelected() {
    for(int i = 0; i < m_data.count(); i++) {
        if(m_data[i].m_selected == true) {
            m_data[i].m_selected = false;
            emit dataChanged( QAbstractListModel::index(i),  QAbstractListModel::index(i));
        }
    }
    setNumberSelectedAlarms(0);
}

bool AlarmItemModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    int row = index.row();
    if(row < 0 || row >= m_data.count()) {
        return false;
    }

    switch (role) {
    case EverydayRole:
        if (value != m_data[row].m_everyday) {
            m_data[row].m_everyday = value.toBool();
            emit dataChanged(index, index);
            return true;
        }
    case ActiveRole:
        if (value != m_data[row].m_active) {
            m_data[row].m_active = value.toBool();
            emit dataChanged(index, index);
            if(m_data[row].m_active)
                setNumberActiveAlarms(m_numberActiveAlarms + 1);
            else
                setNumberActiveAlarms(m_numberActiveAlarms - 1);
            return true;
        }
    case SelectedRole:
        if (value != m_data[row].m_selected) {
            m_data[row].m_selected = value.toBool();
            emit dataChanged(index, index);
            if(m_data[row].m_selected)
                setNumberSelectedAlarms(m_numberSelectedAlarms + 1);
            else
                setNumberSelectedAlarms(m_numberSelectedAlarms - 1);
            return true;
        }
    case DayRole:
        if (value != m_data[row].m_day) {
            m_data[row].m_day = value.toInt();
            emit dataChanged(index, index);
            return true;
        }
    case MonthRole:
        if (value != m_data[row].m_month) {
            m_data[row].m_month = value.toInt();
            emit dataChanged(index, index);
            return true;
        }
    case YearRole:
        if (value != m_data[row].m_year) {
            m_data[row].m_year = value.toInt();
            emit dataChanged(index, index);
            return true;
        }
    case HoursRole:
        if (value != m_data[row].m_hours) {
            m_data[row].m_hours = value.toInt();
            emit dataChanged(index, index);
            return true;
        }
    case MinutesRole:
        if (value != m_data[row].m_minutes) {
            m_data[row].m_minutes = value.toInt();
            emit dataChanged(index, index);
            return true;
        }
        break;
    }

    return false;
}

Qt::ItemFlags AlarmItemModel::flags(const QModelIndex& index) const
{
    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

void AlarmItemModel::addNewAlarm(bool everyDay, QDate date, int hours, int minutes) {

    AlarmItemData alarm(everyDay, true, false, date.day(), date.month(), date.year(), hours, minutes );

    if(alarm.m_everyday)
    {
        int i = 0;
        for(; i < m_data.count(); i++)
        {
            if(m_data[i].m_everyday == false)
                break;
        }
        m_data.insert(i, alarm);

        setNumberEverydayAlarms(m_numberEverydayAlarms + 1);
    }
    else
        m_data.push_back(alarm);

    setDataCount(m_dataCount + 1);
    setNumberActiveAlarms(m_numberActiveAlarms + 1);
}

void AlarmItemModel::setNumberEverydayAlarms(int numberEverydayAlarms) {
    if(m_numberEverydayAlarms != numberEverydayAlarms){
        m_numberEverydayAlarms = numberEverydayAlarms;
        emit numberEverydayAlarmsChanged();
    }
}

void AlarmItemModel::setNumberSelectedAlarms(int numberSelectedAlarms) {
    if(m_numberSelectedAlarms != numberSelectedAlarms){
        m_numberSelectedAlarms = numberSelectedAlarms;
        emit numberSelectedAlarmsChanged();
    }
}

void AlarmItemModel::deleteSelectedAlarms() {

    int numberActiveAlarmsDecrement = 0;
    int numberEverydayAlarmsDecrement = 0;
    int numberSelectedAlarmsDecrement = 0;
    int dataCountDecrement = 0;

    for(int i = 0; i < m_data.count(); ) {
        if(m_data[i].m_selected) {

            if(m_data[i].m_active)
                numberActiveAlarmsDecrement++;
            if(m_data[i].m_everyday)
                numberEverydayAlarmsDecrement++;

            numberSelectedAlarmsDecrement++;
            dataCountDecrement++;

            beginRemoveRows(QModelIndex(),i,i);
            m_data.remove(i);
            endRemoveRows();
        }
        else
            i++;
    }

    setNumberActiveAlarms(m_numberActiveAlarms - numberActiveAlarmsDecrement);
    setNumberEverydayAlarms(m_numberEverydayAlarms  - numberEverydayAlarmsDecrement);
    setNumberSelectedAlarms(m_numberSelectedAlarms - numberSelectedAlarmsDecrement);
    setDataCount(m_dataCount - dataCountDecrement);
}

void AlarmItemModel::setDataCount(int dataCount) {
    if(m_dataCount != dataCount) {
       m_dataCount = dataCount;
       emit dataCountChanged(); 
    }
}

void AlarmItemModel::setNumberActiveAlarms(int numberActiveAlarms) {
    if(m_numberActiveAlarms != numberActiveAlarms){
        m_numberActiveAlarms = numberActiveAlarms;
        emit numberActiveAlarmsChanged();
    }
} 
