#pragma once

#include <QObject>
#include <QTimer>
#include <QDate>
#include "alarmitemmodel.h"

class ClockManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString dateText MEMBER m_dateText NOTIFY dateTextChanged)
    Q_PROPERTY(int minutes MEMBER m_minutes NOTIFY minutesChanged)
    Q_PROPERTY(int hours MEMBER m_hours NOTIFY hoursChanged)
    Q_PROPERTY(bool timerRunning MEMBER m_timerRunning NOTIFY timerRunningChanged)
    Q_PROPERTY(float timerCurrentSeconds MEMBER m_timerCurrentSeconds NOTIFY timerCurrentSecondsChanged WRITE setTimerCurrentSeconds)
    Q_PROPERTY(int secondsInOneMinute MEMBER SECONDS_IN_ONE_MINUTE CONSTANT)
    Q_PROPERTY(int timeOfTheDissolveAnimation MEMBER TIME_OF_THE_DISSOLVE_ANIMATION CONSTANT)
    Q_PROPERTY(QDate alarmDate MEMBER m_alarmDate NOTIFY alarmDateChanged)
    Q_PROPERTY(AlarmItemModel* alarmItemModel READ getAlarmItemModel CONSTANT)

    QString m_dateText;
    int m_minutes;
    int m_hours;
    bool m_timerRunning;
    float m_timerCurrentSeconds;
    QDate m_alarmDate;
    AlarmItemModel m_alarmItemModel;

    QTimer m_timerForRefresh;
    int m_timerHoursOnStartTimer;
    int m_timerMinutesOnStartTimer;

public:
    explicit ClockManager(QObject *parent = nullptr);
    void setTimerCurrentSeconds(float timerCurrentSeconds);

    static constexpr int TIME_OF_THE_DISSOLVE_ANIMATION = 500;
    static constexpr int MINUTES_IN_ONE_HOUR = 60;
    static constexpr int SECONDS_TIMER_INTERVAL = 20;
    static constexpr int SECONDS_IN_ONE_MINUTE = 60;
    static constexpr int HOURS_IN_A_DAY = 24;

public slots:
    void setTimerCurrentTime(int hours, int minutes);
    void restartTimer();
    AlarmItemModel* getAlarmItemModel(){return &m_alarmItemModel;}

signals:
    void dateTextChanged();
    void minutesChanged();
    void hoursChanged();
    void timerMinutesChanged();
    void timerHoursChanged();
    void timerRunningChanged();
    void timerCurrentSecondsChanged();
    void alarmDateChanged();

protected:

private slots:
    void refresh();

private:
    void refreshTime();
    void refreshDateText();
    void decreaseTimerCurrentSeconds();
    float convertHoursAndMinutesToSeconds(int hours, int minutes);
};

