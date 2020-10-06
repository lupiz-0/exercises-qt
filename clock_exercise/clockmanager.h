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

    QString m_dateText;
    int m_minutes;
    int m_hours;
    QTimer m_timerForRefresh;

public:
    explicit ClockManager(QObject *parent = nullptr);

    static constexpr int TIME_OF_THE_DISSOLVE_ANIMATION = 500;

public slots:

signals:
    void dateTextChanged();
    void minutesChanged();
    void hoursChanged();

protected:

private slots:
    void refresh();

private:
    void refreshTime();
    void refreshDateText();
};
