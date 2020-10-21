#pragma once
#include <QObject>

struct AlarmItemData {

    AlarmItemData() = default;
    AlarmItemData(bool everyday, bool active, bool selected, int day, int month, int year, int hours, int minutes)
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
