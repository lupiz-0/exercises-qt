#include <QtTest>
#include <sstream>
#include "../date.h"

// add necessary includes here

class testDate : public QObject
{
    Q_OBJECT

public:
    testDate();
    ~testDate();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void defaultConstructorTest();
    void notDefaultConstructorTest();
    void insertionOperatorTest();
    void equalityOperatorTest();
private:
    static bool isDefaultDate(const Date& date);
};

testDate::testDate()
{

}

testDate::~testDate()
{

}

void testDate::initTestCase()
{

}

void testDate::cleanupTestCase()
{

}

void testDate::defaultConstructorTest() {
    Date date;
    QVERIFY(isDefaultDate(date));
}

void testDate::notDefaultConstructorTest() {
    Date date(23, Date::October, 2020);
    QCOMPARE(date.day(), 23);
    QCOMPARE(date.month(), Date::October);
    QCOMPARE(date.year(), 2020);
}

void testDate::insertionOperatorTest() {
    Date date(23, Date::October, 2020);
    std::stringstream out;
    out << date;
    QCOMPARE(out.str(), "23/10/2020");
}

void testDate::equalityOperatorTest() {
    Date dateA(23, Date::October, 2020);
    Date dateB(23, Date::October, 2020);
    QVERIFY(dateA == dateB);
}

bool testDate::isDefaultDate(const Date& date) {
    return date.day() == 1 && date.month() == Date::January && date.year() == 1970;
}

QTEST_APPLESS_MAIN(testDate)

#include "tst_date.moc"
