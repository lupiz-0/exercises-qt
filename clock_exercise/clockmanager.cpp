#include <QTime>
#include<QDebug>
#include <QtGlobal>
#include "clockmanager.h"
#include "notifierofchange.h"

//int m_timerHoursOnStartTimer;
//int m_timerMinutesOnStartTimer;

ClockManager::ClockManager(QObject *parent) : QObject(parent), m_timerMinutes(0), m_timerHours(0), m_timerIsInPlay(false), m_timerForRefresh(this), m_timerCurrentSeconds(0)
  , m_timerHoursOnStartTimer(0), m_timerMinutesOnStartTimer(0)
{
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
    if(m_timerIsInPlay)
        decreaseTimerCurrentSeconds();
}

float ClockManager::convertHoursAndMinutesToSeconds(int hours, int minutes) {
    return (hours*MINUTES_IN_ONE_HOUR + minutes)*SECONDS_IN_ONE_MINUTE;
}

void ClockManager::restartTimer() {
    NotifierOfChange timerCurrentSecondsNotifier(m_timerCurrentSeconds);

    m_timerCurrentSeconds = convertHoursAndMinutesToSeconds(m_timerHoursOnStartTimer, m_timerMinutesOnStartTimer);
    refreshTimerHoursAndMinutes();

    if(timerCurrentSecondsNotifier.isChanged(m_timerCurrentSeconds)) emit timerCurrentSecondsChanged();
}

void ClockManager::setTimerCurrentTime(int hours, int minutes) {
    NotifierOfChange timerCurrentSecondsNotifier(m_timerCurrentSeconds);

    m_timerHoursOnStartTimer = hours;
    m_timerMinutesOnStartTimer = minutes;
    m_timerCurrentSeconds = convertHoursAndMinutesToSeconds(hours, minutes);
    refreshTimerHoursAndMinutes();

    if(timerCurrentSecondsNotifier.isChanged(m_timerCurrentSeconds)) emit timerCurrentSecondsChanged();
}

void ClockManager::refreshTimerHoursAndMinutes() {

    int prevHours = m_timerHours;
    int prevMinutes = m_timerMinutes;

    m_timerHours = (int)(m_timerCurrentSeconds/SECONDS_IN_ONE_MINUTE) / MINUTES_IN_ONE_HOUR;
    m_timerMinutes = (int)(m_timerCurrentSeconds/SECONDS_IN_ONE_MINUTE) % MINUTES_IN_ONE_HOUR;

    if(m_timerHours != prevHours)
        emit timerHoursChanged();

    if(m_timerMinutes != prevMinutes)
        emit timerMinutesChanged();
}

void ClockManager::decreaseTimerCurrentSeconds() {
    NotifierOfChange timerCurrentSecondsNotifier(m_timerCurrentSeconds);

    m_timerCurrentSeconds -= SECONDS_TIMER_INTERVAL;
    m_timerCurrentSeconds = qMax(0.0f, (float)m_timerCurrentSeconds);
    refreshTimerHoursAndMinutes();

    if(timerCurrentSecondsNotifier.isChanged(m_timerCurrentSeconds)) emit timerCurrentSecondsChanged();
}
