#include <QTime>
#include <memory>
#include<QDebug>
#include "clockmanager.h"



ClockManager::ClockManager(QObject *parent) : QObject(parent), mTimerForRefresh(new QTimer())
{
    connect(mTimerForRefresh.get(), &QTimer::timeout, this, &ClockManager::refresh);
    mTimerForRefresh->start(1000);

    refresh();
}

int ClockManager::testfunction(int number)
{
    return number*2;
}

void ClockManager::refreshDateText() {
    QString previousDateText = mDateText;
    mDateText = QDate::currentDate().toString("dddd dd MMMM");
    if(mDateText != previousDateText)
        dateTextChanged();
}

void ClockManager::refreshClockHandsAngles() {

    float previousHoursClockHandsAngle = mHoursClockHandsAngle;
    float previousMinutesClockHandsAngle = mMinutesClockHandsAngle;

    QTime time = QTime::currentTime();
    mMinutesClockHandsAngle = time.minute()/60.0f*360.0f - 90.0f + time.second()/60.0f*(360.0f/60.0f);
    mHoursClockHandsAngle = time.hour();
    if(mHoursClockHandsAngle > 12.0f)
        mHoursClockHandsAngle -= 12.0f;
    mHoursClockHandsAngle = mHoursClockHandsAngle/12.0f*360.0f - 90.0f;

    if(mHoursClockHandsAngle != previousHoursClockHandsAngle)
        hoursClockHandsAngleChanged();

    if(mMinutesClockHandsAngle != previousMinutesClockHandsAngle)
        minutesClockHandAngleChanged();
}

void ClockManager::refresh()
{
    refreshDateText();
    refreshClockHandsAngles();
}

