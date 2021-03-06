#include <QTime>
#include<QDebug>
#include <QtGlobal>
#include "clockmanager.h"
#include "notifierofchange.h"

ClockManager::ClockManager(QObject *parent) : QObject(parent), m_timerRunning(false), m_timerCurrentSeconds(0)
        , m_timerHoursOnStartTimer(0), m_timerMinutesOnStartTimer(0) {
    connect(&m_timerForRefresh, &QTimer::timeout, this, &ClockManager::refresh);
    m_timerForRefresh.start(SECONDS_TIMER_INTERVAL*1000);
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
    int previousHours = m_hours;
    int previousMinutes = m_minutes;

    QTime time = QTime::currentTime();
    m_minutes = time.minute();
    m_hours = time.hour();

    if(m_hours != previousHours)
        emit hoursChanged();

    if(m_minutes != previousMinutes)
        emit minutesChanged();
}

void ClockManager::refresh() {
    refreshDateText();
    refreshTime();
    if(m_timerRunning)
        decreaseTimerCurrentSeconds();
}

float ClockManager::convertHoursAndMinutesToSeconds(int hours, int minutes) {
    return (hours*MINUTES_IN_ONE_HOUR + minutes)*SECONDS_IN_ONE_MINUTE;
}

void ClockManager::restartTimer() {
    setTimerCurrentSeconds(convertHoursAndMinutesToSeconds(m_timerHoursOnStartTimer, m_timerMinutesOnStartTimer));
}

void ClockManager::setTimerCurrentTime(int hours, int minutes) {
    m_timerHoursOnStartTimer = hours;
    m_timerMinutesOnStartTimer = minutes;
    setTimerCurrentSeconds(convertHoursAndMinutesToSeconds(hours, minutes));
}

void ClockManager::decreaseTimerCurrentSeconds() {
    NotifierOfChange timerCurrentSecondsNotifier( m_timerCurrentSeconds,
        [this]() {
            emit timerCurrentSecondsChanged();
        });

    m_timerCurrentSeconds -= SECONDS_TIMER_INTERVAL;
    m_timerCurrentSeconds = qMax(0.0f, (float)m_timerCurrentSeconds);
}

void ClockManager::setTimerCurrentSeconds(float timerCurrentSeconds) {
    if(m_timerCurrentSeconds != timerCurrentSeconds) {
        m_timerCurrentSeconds = timerCurrentSeconds;
        emit timerCurrentSecondsChanged();
    }
}

void ClockManager::setAlarmEverydayModality(bool alarmEverydayModality) {
    if(m_alarmEverydayModality != alarmEverydayModality) {
        m_alarmEverydayModality = alarmEverydayModality;
        emit alarmEverydayModalityChanged();
    }
}

void ClockManager::setDateAlarmValid(bool dateAlarmValid) {
    if(m_dateAlarmValid != dateAlarmValid) {
        m_dateAlarmValid = dateAlarmValid;
        dateAlarmValidChanged();
    }
}
