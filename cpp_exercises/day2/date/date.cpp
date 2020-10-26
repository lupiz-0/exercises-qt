#include "date.h"
#include <iostream>
#include <iomanip>
#include <limits.h>

std::ostream& operator<<(std::ostream& ostream, const Date& date) {
    ostream << std::setfill('0') << std::setw(2) << date.day() << '/' << std::setfill('0') << std::setw(2) << date.month() << '/' << date.year();
    return ostream;
}

bool operator==(const Date& dateA, const Date& dateB) {
    return dateA.day() == dateB.day() && dateA.month() == dateB.month() && dateA.year() == dateB.year();
}

Date::Date(int day, int month, int year){
    int dayZeroBase = day - 1;
    int monthZeroBase = month - 1;
    if(isDateValid(dayZeroBase, monthZeroBase, year)) {
        m_day = dayZeroBase;
        m_month = monthZeroBase;
        m_year = year;
    }
    else {
        m_day = Date::DEFAULT_DAY_ZERO_BASE;
        m_month = Date::DEFAULT_MONTH_ZERO_BASE;
        m_year = Date::DEFAULT_YEAR;
    }
}

bool Date::isLeapYear(int year) {
    return year % 100 == 0? (year % 400 == 0):(year % 4 == 0);
}

int Date::getMonthDays(int month, int year) {
    return (Date::isLeapYear(year) && month == Date::FebruaryZeroBase) ? (Date::MONTHS_DAYS[month] + 1) : (Date::MONTHS_DAYS[month]) ;
}

bool Date::isYearValid(int year) {
    return year >= 0 && year < INT_MAX;
}

bool Date::isMonthValid(int month) {
    return month >= 0 && month < 12;
}

bool Date::isDayValid(int day, int month, int year) {
    return day >= 0 && day < Date::getMonthDays(month, year);
}

bool Date::isDateValid(int day, int month, int year){
    return isYearValid(year) && isMonthValid(month) && isDayValid(day, month, year);
}

bool Date::compare(int day, int month, int year) {
    return day - 1 == m_day && month - 1 == m_month && year == m_year;
}
