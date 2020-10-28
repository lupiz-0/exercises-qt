#include "date.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
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
    if(month == Date::FebruaryZeroBase && Date::isLeapYear(year))
        return Date::MONTHS_DAYS[month] + 1;
    return Date::MONTHS_DAYS[month];
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

std::string Date::toString() const {
    std::stringstream stringstream;
    stringstream << std::setfill('0') << std::setw(2) << day() << "/" << std::setfill('0') << std::setw(2) << month() << "/" << std::setfill('0') << std::setw(4) << year();
    return stringstream.str();
}

void Date::addYears(int years) {
    addYearsWithoutDayCut(years);
    clampDayDependingMonthYear();
}

void Date::clampDayDependingMonthYear() {
    m_day = std::clamp(m_day, 0, Date::getMonthDays(m_month, m_year) - 1);
}

void Date::addYearsWithoutDayCut(int years) {
    years = std::clamp(years, -2000, 2000);
    m_year += years;
    m_year = std::max(m_year, 0);
}

void Date::addMonths(int months) {
    int yearsNumber = months / 12;
    months %= 12;
    m_month += months;
    if(m_month < 0) {
        yearsNumber--;
        m_month = 12 + m_month;
    } else if(m_month >= 12) {
        yearsNumber++;
        m_month %= 12;
    }
    addYearsWithoutDayCut(yearsNumber);
    clampDayDependingMonthYear();
}

qint64 Date::toJulianDay()
{
    return (1461 * (year() + 4800 + (month() - 14)/12))/4 +(367 * (month() - 2 - 12 * ((month() - 14)/12)))/12 - (3 * ((year() + 4900 + (month() - 14)/12)/100))/4 + day() - 32075;
}

