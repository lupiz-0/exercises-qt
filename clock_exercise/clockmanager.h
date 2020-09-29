#ifndef CLOCKMANAGER_H
#define CLOCKMANAGER_H

#include <QObject>
#include <QTimer>
#include <memory>

class ClockManager : public QObject
{
    Q_OBJECT
public:
    explicit ClockManager(QObject *parent = nullptr);

    Q_PROPERTY(QString dateText MEMBER mDateText NOTIFY dateTextChanged)
    Q_PROPERTY(float minutesClockHandAngle MEMBER mMinutesClockHandsAngle NOTIFY minutesClockHandAngleChanged)
    Q_PROPERTY(float hoursClockHandAngle MEMBER mHoursClockHandsAngle NOTIFY hoursClockHandsAngleChanged)

    QString mDateText;
    float mMinutesClockHandsAngle;
    float mHoursClockHandsAngle;

public slots:
    int testfunction(int number);
    void refresh();

signals:
    void dateTextChanged();
    void minutesClockHandAngleChanged();
    void hoursClockHandsAngleChanged();

private slots:


private:
    void refreshClockHandsAngles();
    void refreshDateText();


    std::unique_ptr<QTimer> mTimerForRefresh;
};

#endif // CLOCKMANAGER_H
