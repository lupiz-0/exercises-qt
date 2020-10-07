#pragma once

#include <QObject>
#include <QTimer>

class ClockManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString dateText MEMBER m_dateText NOTIFY dateTextChanged)
    Q_PROPERTY(int minutes MEMBER m_minutes NOTIFY minutesChanged)
    Q_PROPERTY(int hours MEMBER m_hours NOTIFY hoursChanged)
    Q_PROPERTY(int timeOfTheDissolveAnimation MEMBER TIME_OF_THE_DISSOLVE_ANIMATION CONSTANT)
    Q_PROPERTY(bool timerRunning MEMBER m_timerRunning NOTIFY timerRunningChanged)
    Q_PROPERTY(float timerCurrentSeconds MEMBER m_timerCurrentSeconds NOTIFY timerCurrentSecondsChanged WRITE setTimerCurrentSeconds)
    Q_PROPERTY(int secondsInOneMinute MEMBER SECONDS_IN_ONE_MINUTE CONSTANT)
    Q_PROPERTY(int alarmDay MEMBER m_alarmDay NOTIFY alarmDayChanged WRITE setAlarmDay)
    Q_PROPERTY(int alarmMonth MEMBER m_alarmMonth NOTIFY alarmMonthChanged WRITE setAlarmMonth)
    Q_PROPERTY(int alarmYear MEMBER m_alarmYear NOTIFY alarmYearChanged WRITE setAlarmYear)

    QString m_dateText;
    int m_minutes;
    int m_hours;
    bool m_timerRunning;

    QTimer m_timerForRefresh;
    float m_timerCurrentSeconds;
    int m_timerHoursOnStartTimer;
    int m_timerMinutesOnStartTimer;
    int m_alarmDay;
    int m_alarmMonth;
    int m_alarmYear;

public:
    explicit ClockManager(QObject *parent = nullptr);
    void setTimerCurrentSeconds(float timerCurrentSeconds);
    void setAlarmDay(int alarmDay);
    void setAlarmMonth(int alarmMonth);
    void setAlarmYear(int alarmYear);

    static constexpr int TIME_OF_THE_DISSOLVE_ANIMATION = 500;

    static constexpr int MINUTES_IN_ONE_HOUR = 60;
    static constexpr int SECONDS_TIMER_INTERVAL = 20;
    static constexpr int SECONDS_IN_ONE_MINUTE = 60;
    static constexpr int HOURS_IN_A_DAY = 24;

public slots:
    void setTimerCurrentTime(int hours, int minutes);
    void restartTimer();
    void setCurrentDateOnTheAlarm();

signals:
    void dateTextChanged();
    void minutesChanged();
    void hoursChanged();
    void timerMinutesChanged();
    void timerHoursChanged();
    void timerRunningChanged();
    void timerCurrentSecondsChanged();
    void alarmDayChanged();
    void alarmMonthChanged();
    void alarmYearChanged();

protected:

private slots:
    void refresh();

private:
    void refreshTime();
    void refreshDateText();
    void decreaseTimerCurrentSeconds();
    float convertHoursAndMinutesToSeconds(int hours, int minutes);
    void noneExp(){};
};
