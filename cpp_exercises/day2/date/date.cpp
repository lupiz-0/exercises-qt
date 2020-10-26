#include "date.h"
#include <iomanip>


std::ostream& operator<<(std::ostream& ostream, const Date& date) {
    ostream << std::setfill('0') << std::setw(2) << date.day() << '/' << std::setfill('0') << std::setw(2) << date.month() << '/' << date.year();
    return ostream;
}

bool operator==(const Date& dateA, const Date& dateB) {
    return dateA.day() == dateB.day() && dateA.month() == dateB.month() && dateA.year() == dateB.year();
}

bool Date::isLeapYear(int year) {
    return year % 100 == 0? (year % 400 == 0):(year % 4 == 0);
}

int Date::getMonthDays(int month, int year) {
    return (Date::isLeapYear(year) && month == Date::FebruaryZeroBase) ? (Date::MONTHS_DAYS[month] + 1) : (Date::MONTHS_DAYS[month]) ;
}

bool Date::compare(int day, int month, int year) {
    return day - 1 == m_day && month - 1 == m_month && year == m_year;
}
