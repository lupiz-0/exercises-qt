#pragma once
#include <QObject>

struct AlarmItemData {
    Q_GADGET

    Q_PROPERTY(bool everyday    MEMBER m_everyday)
    Q_PROPERTY(bool active      MEMBER m_active)
    Q_PROPERTY(bool selected    MEMBER m_selected)
    Q_PROPERTY(int day         MEMBER m_day)
    Q_PROPERTY(int month       MEMBER m_month)
    Q_PROPERTY(int year        MEMBER m_year)
    Q_PROPERTY(int hours       MEMBER m_hours)
    Q_PROPERTY(int minutes     MEMBER m_minutes)

public:
    AlarmItemData() = default;
    AlarmItemData(const bool& everyday, const bool& active, const bool& selected, const int& day, const int& month, const int& year, const int& hours, const int& minutes)
        : m_everyday(everyday), m_active(active), m_selected(selected), m_day(day), m_month(month), m_year(year), m_hours(hours), m_minutes(minutes) {}

    bool m_everyday;
    bool m_active;
    bool m_selected;
    int m_day;
    int m_month;
    int m_year;
    int m_hours;
    int m_minutes;
};
