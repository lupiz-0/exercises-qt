#include "date.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits.h>
#include <stdlib.h>

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

/*!
 * references: https://en.wikipedia.org/wiki/Julian_day
 */

int64_t Date::toJulianDay()
{
    return (1461 * (year() + 4800 + (month() - 14)/12))/4 +(367 * (month() - 2 - 12 * ((month() - 14)/12)))/12 - (3 * ((year() + 4900 + (month() - 14)/12)/100))/4 + day() - 32075;
}

/*!
 * references: https://en.wikipedia.org/wiki/Julian_day
 */

void Date::fromJulianDay(int64_t julianDay) {
    int64_t y = 4716;
    int64_t v = 3;
    int64_t j = 1401;
    int64_t u = 5;
    int64_t m = 2;
    int64_t s = 153;
    int64_t n = 12;
    int64_t w = 2;
    int64_t r = 4;
    int64_t B = 274277;
    int64_t p = 1461;
    int64_t C  = -38;

    int64_t f = julianDay + j + (((4 * julianDay + B) / 146097) * 3) / 4 + C;

    int64_t e = r * f + v;
    int64_t g = (e%p) / r;
    int64_t h = u * g + w;
    int64_t D = (h%s) / u + 1;
    int64_t M = (h / s + m)%n + 1;

    m_year = e/p - y + (n + m - M) / n;
    m_day = D - 1;
    m_month = M - 1;
}

void Date::addDays(int days) {
    fromJulianDay(toJulianDay() + days);
}

bool Date::areStringValidInteger(const std::string& string) {
    char* p;
    strtol(string.c_str(), &p, 10);
    return *p == 0;
}

void Date::splitDayMonthYearString(const std::string& string, std::string& dayString, std::string& monthString, std::string& yearString) {
    char separator = '-';
    std::stringstream stringStream(string);
    std::getline(stringStream, dayString, separator);
    std::getline(stringStream, monthString, separator);
    std::getline(stringStream, yearString, separator);
}
