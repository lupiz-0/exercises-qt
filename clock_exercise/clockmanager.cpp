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

void ClockManager::setCurrentDate() {
    QDate date = QDate::currentDate();
    setDate(date.day(), date.month(), date.year());
    setDateNames(date.toString("ddd"), date.toString("MMM"));
}

void ClockManager::setCurrentAlarmDate() {
    QDate date = QDate::currentDate();
    setAlarmDate(date.day(), date.month(), date.year());
}

void ClockManager::setDayOfDate(int dayOfDate) {
    if(m_dayOfDate != dayOfDate) {
        m_dayOfDate = dayOfDate;
        dayOfDateChanged();
    }
}

void ClockManager::setMonthOfDate(int monthOfDate) {
    if(m_monthOfDate != monthOfDate) {
        m_monthOfDate = monthOfDate;
        monthOfDateChanged();
    }
}

void ClockManager::setYearOfDate(int yearOfDate) {
    if(m_yearOfDate != yearOfDate) {
        m_yearOfDate = yearOfDate;
        yearOfDateChanged();
    }
}

void ClockManager::addToDate(int daysNumber, int monthsNumber, int yearsNumber) {
    QDate date(m_yearOfDate, m_monthOfDate, m_dayOfDate);
    date = date.addDays(daysNumber);
    date = date.addMonths(monthsNumber);
    date = date.addYears(yearsNumber);
    setDate(date.day(), date.month(), date.year());
    setDateNames(date.toString("ddd"), date.toString("MMM"));
}

void ClockManager::setDate(int days, int months, int years) {
    setDayOfDate(days);
    setMonthOfDate(months);
    setYearOfDate(years);
}

void ClockManager::setAlarmDate(int days, int months, int years) {
    setAlarmDay(days);
    setAlarmMonth(months);
    setAlarmYear(years);
}

void ClockManager::setDayOfDateName(QString dayOfDateName) {
    if(m_dayOfDateName != dayOfDateName) {
        m_dayOfDateName = dayOfDateName;
        dayOfDateNameChanged();
    }
}

void ClockManager::setMonthOfDateName(QString monthOfDateName) {
    if(m_monthOfDateName != monthOfDateName) {
        m_monthOfDateName = monthOfDateName;
        monthOfDateNameChanged();
    }
}

void ClockManager::setDateNames(QString day, QString month) {
    setDayOfDateName(day);
    setMonthOfDateName(month);
}

void ClockManager::setAlarmDay(int alarmDay) {
    if(m_alarmDay != alarmDay){
        m_alarmDay = alarmDay;
        alarmDayChanged();
    }
}

void ClockManager::setAlarmMonth(int alarmMonth) {
    if(m_alarmMonth != alarmMonth) {
        m_alarmMonth = alarmMonth;
        alarmMonthChanged();
    }
}

void ClockManager::setAlarmYear(int alarmYear){
    if(m_alarmYear != alarmYear) {
        m_alarmYear = alarmYear;
        alarmYearChanged();
    }
}

void ClockManager::confirmAlarmDate() {
    setAlarmDate(m_dayOfDate, m_monthOfDate, m_yearOfDate);
}

void ClockManager::setDateOfDatePageLikeDateOfAlarm(){
    setDate(m_alarmDay, m_alarmMonth, m_alarmYear);
    QDate date(m_alarmYear, m_alarmMonth, m_alarmDay);
    setDateNames(date.toString("ddd"), date.toString("MMM"));
}
