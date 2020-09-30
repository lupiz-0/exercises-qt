#include <QTime>
#include<QDebug>
#include "clockmanager.h"



ClockManager::ClockManager(QObject *parent) : QObject(parent), m_timerForRefresh(this)
{
    connect(&m_timerForRefresh, &QTimer::timeout, this, &ClockManager::refresh);
    m_timerForRefresh.start(20000);

    refresh();
}

void ClockManager::refreshDateText() {
    QString newDateText = QDate::currentDate().toString("dddd dd MMMM");
    if(newDateText == m_dateText)
        return;
    m_dateText = newDateText;
    emit dateTextChanged();
}

void ClockManager::refreshTime() {
    float previousHours = m_hours;
    float previousMinutes = m_minutes;

    QTime time = QTime::currentTime();
    m_minutes = time.minute();
    m_hours = time.hour();

    if(m_hours != previousHours)
        emit hoursChanged();

    if(m_minutes != previousMinutes)
        emit minutesChanged();
}

void ClockManager::refresh()
{
    refreshDateText();
    refreshTime();
}

