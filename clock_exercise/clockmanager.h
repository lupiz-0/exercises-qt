#pragma once

#include <QObject>
#include <QTimer>

class ClockManager : public QObject
{
    Q_OBJECT

    // ↓↓↓ properties
    Q_PROPERTY(QString dateText MEMBER m_dateText NOTIFY dateTextChanged)
    Q_PROPERTY(int minutes MEMBER m_minutes NOTIFY minutesChanged)
    Q_PROPERTY(int hours MEMBER m_hours NOTIFY hoursChanged)
    Q_PROPERTY(bool timerRunning MEMBER m_timerRunning NOTIFY timerRunningChanged)
    Q_PROPERTY(float timerCurrentSeconds MEMBER m_timerCurrentSeconds NOTIFY timerCurrentSecondsChanged WRITE setTimerCurrentSeconds)
    Q_PROPERTY(int dayOfDate MEMBER m_dayOfDate NOTIFY dayOfDateChanged WRITE setDayOfDate)
    Q_PROPERTY(int monthOfDate MEMBER m_monthOfDate NOTIFY monthOfDateChanged WRITE setMonthOfDate)
    Q_PROPERTY(int yearOfDate MEMBER m_yearOfDate NOTIFY yearOfDateChanged WRITE setYearOfDate)
    Q_PROPERTY(QString dayOfDateName MEMBER m_dayOfDateName NOTIFY dayOfDateNameChanged WRITE setDayOfDateName)
    Q_PROPERTY(QString monthOfDateName MEMBER m_monthOfDateName NOTIFY monthOfDateNameChanged WRITE setMonthOfDateName)
    Q_PROPERTY(int secondsInOneMinute MEMBER SECONDS_IN_ONE_MINUTE CONSTANT)
    Q_PROPERTY(int alarmDay MEMBER m_alarmDay NOTIFY alarmDayChanged WRITE setAlarmDay)
    Q_PROPERTY(int alarmMonth MEMBER m_alarmMonth NOTIFY alarmMonthChanged WRITE setAlarmMonth)
    Q_PROPERTY(int alarmYear MEMBER m_alarmYear NOTIFY alarmYearChanged WRITE setAlarmYear)
    Q_PROPERTY(QString alarmDayName MEMBER m_alarmDayName NOTIFY alarmDayNameChanged WRITE setAlarmDayName)
    Q_PROPERTY(QString alarmMonthName MEMBER m_alarmMonthName NOTIFY alarmMonthNameChanged WRITE setAlarmMonthName)
    Q_PROPERTY(int timeOfTheDissolveAnimation MEMBER TIME_OF_THE_DISSOLVE_ANIMATION CONSTANT)
    Q_PROPERTY(int alarmDay MEMBER m_alarmDay NOTIFY alarmDayChanged WRITE setAlarmDay)
    Q_PROPERTY(int alarmMonth MEMBER m_alarmMonth NOTIFY alarmMonthChanged WRITE setAlarmMonth)
    Q_PROPERTY(int alarmYear MEMBER m_alarmYear NOTIFY alarmYearChanged WRITE setAlarmYear)

    QString m_dateText;
    int m_minutes;
    int m_hours;
    bool m_timerRunning;
    float m_timerCurrentSeconds;
    int m_dayOfDate;
    int m_monthOfDate;
    int m_yearOfDate;
    QString m_dayOfDateName;
    QString m_monthOfDateName;
    int m_alarmDay;
    int m_alarmMonth;
    int m_alarmYear;
    // ↑↑↑ properties

    // ↓↓↓ not properties
    QTimer m_timerForRefresh;
    int m_timerHoursOnStartTimer;
    int m_timerMinutesOnStartTimer;
    // ↑↑↑ not properties

public:
    explicit ClockManager(QObject *parent = nullptr);
    void setTimerCurrentSeconds(float timerCurrentSeconds);
    void setDayOfDate(int dayOfDate);
    void setMonthOfDate(int monthOfDate);
    void setYearOfDate(int yearOfDate);
    void setDayOfDateName(QString dayOfDateName);
    void setMonthOfDateName(QString monthOfDateName);
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
    void setCurrentDate();
    void setCurrentAlarmDate();
    void addToDate(int daysNumber, int monthsNumber, int yearsNumber);
    void confirmAlarmDate();
    void setDateOfDatePageLikeDateOfAlarm();

signals:
    void dateTextChanged();
    void minutesChanged();
    void hoursChanged();
    void timerMinutesChanged();
    void timerHoursChanged();
    void timerRunningChanged();
    void timerCurrentSecondsChanged();
    void dayOfDateChanged();
    void monthOfDateChanged();
    void yearOfDateChanged();
    void dayOfDateNameChanged();
    void monthOfDateNameChanged();
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
    void setDate(int days, int months, int years);
    void setDateNames(QString day, QString month);
    void setAlarmDate(int days, int months, int years);
};
