#pragma once
#include <iostream>

class Date
{
public:
    enum Month {
        January = 1,
        February,
        March,
        April,
        May,
        June,
        July,
        August,
        September,
        October,
        November,
        December
    };

    Date(): Date(DEFAULT_DAY_ZERO_BASE, DEFAULT_MONTH_ZERO_BASE, DEFAULT_YEAR){}

    Date(int day, int month, int year): m_day(day - 1), m_month(month - 1), m_year(year){}

    int day() const {return m_day + 1;}
    int month() const {return m_month + 1;}
    int year() const {return m_year;}
    bool compare(int day, int month, int year);

private:
    enum MonthZeroBase {
        JanuaryZeroBase = 0,
        FebruaryZeroBase,
        MarchZeroBase,
        AprilZeroBase,
        MayZeroBase,
        JuneZeroBase,
        JulyZeroBase,
        AugustZeroBase,
        SeptemberZeroBase,
        OctoberZeroBase,
        NovemberZeroBase,
        DecemberZeroBase
    };
    static bool isLeapYear(int year);
    static int getMonthDays(int month, int year);

    int m_day;
    int m_month;
    int m_year;

    static constexpr int DEFAULT_DAY_ZERO_BASE = 0;
    static constexpr int DEFAULT_MONTH_ZERO_BASE = 0;
    static constexpr int DEFAULT_YEAR = 1970;
    constexpr static int MONTHS_DAYS[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

std::ostream& operator<<(std::ostream& ostream, const Date& date);
bool operator==(const Date& dateA, const Date& dateB);
