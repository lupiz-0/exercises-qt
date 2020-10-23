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

    Date(): Date(1, Date::January, 1970){}

    Date(int day, int month, int year): m_day(day - 1), m_month(month - 1), m_year(year){}

    int day() const {return m_day + 1;}
    int month() const {return m_month + 1;}
    int year() const {return m_year;}

private:
    bool isLeapYear(int year);

    int m_day;
    int m_month;
    int m_year;

    int m_monthsDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

std::ostream& operator<<(std::ostream& ostream, const Date& date);
bool operator==(const Date& dateA, const Date& dateB);
