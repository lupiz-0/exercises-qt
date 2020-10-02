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

    Q_PROPERTY(int timerMinutes MEMBER m_timerMinutes NOTIFY timerMinutesChanged)
    Q_PROPERTY(int timerHours MEMBER m_timerHours NOTIFY timerHoursChanged)
    Q_PROPERTY(bool timerIsInPlay MEMBER m_timerIsInPlay NOTIFY timerIsInPlayChanged)
    Q_PROPERTY(float timerCurrentSeconds MEMBER m_timerCurrentSeconds NOTIFY timerCurrentSecondsChanged)

    QString m_dateText;
    int m_minutes;
    int m_hours;
    int m_timerMinutes;
    int m_timerHours;
    bool m_timerIsInPlay;

    QTimer m_timerForRefresh;
    float m_timerCurrentSeconds;
    int m_timerHoursOnStartTimer;
    int m_timerMinutesOnStartTimer;

public:
    explicit ClockManager(QObject *parent = nullptr);

    static constexpr int TIME_OF_THE_DISSOLVE_ANIMATION = 500;

    static constexpr int MINUTES_IN_ONE_HOUR = 60;
    static constexpr int SECONDS_TIMER_INTERVAL = 20;
    static constexpr int SECONDS_IN_ONE_MINUTE = 60;

public slots:
    void setTimerCurrentTime(int hours, int minutes);
    void restartTimer();

signals:
    void dateTextChanged();
    void minutesChanged();
    void hoursChanged();
    void timerMinutesChanged();
    void timerHoursChanged();
    void timerIsInPlayChanged();
    void timerCurrentSecondsChanged();

protected:

private slots:
    void refresh();

private:
    void refreshTime();
    void refreshDateText();
    void refreshTimerHoursAndMinutes();
    void decreaseTimerCurrentSeconds();
    float convertHoursAndMinutesToSeconds(int hours, int minutes);
};
