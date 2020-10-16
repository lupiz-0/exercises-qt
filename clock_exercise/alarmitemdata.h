#pragma once
#include <QObject>

struct AlarmItemData {

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
