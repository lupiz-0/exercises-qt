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


char *toString(const Date &date)
{
    return QTest::toString(date.toString().c_str());
}

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
    QCOMPARE(date.day(), 1);
    QCOMPARE(date.month(), 1);
    QCOMPARE(date.year(), 1970);
}

void testDate::notDefaultConstructorTest() {
    Date date0(26, Date::October, 2020);
    QVERIFY(date0.compare(26, Date::October, 2020));

    Date date1(26, Date::October, -1);
    QVERIFY(isDefaultDate(date1));

    Date date2(26, Date::October, 0);
    QVERIFY(date2.compare(26, Date::October, 0));

    Date date3(26, 0, 2020);
    QVERIFY(isDefaultDate(date3));

    Date date4(26, 1, 2020);
    QVERIFY(date4.compare(26, 1, 2020));

    Date date5(26, 13, 2020);
    QVERIFY(isDefaultDate(date5));

    Date date6(26, 12, 2020);
    QVERIFY(date6.compare(26, 12, 2020));

    Date date7(1, Date::November, 2020);
    QVERIFY(date7.compare(1, Date::November, 2020));

    Date date8(0, Date::November, 2020);
    QVERIFY(isDefaultDate(date8));

    Date date9(30, Date::November, 2020);
    QVERIFY(date9.compare(30, Date::November, 2020));

    Date date10(31, Date::November, 2020);
    QVERIFY(isDefaultDate(date10));

    Date date11(29, Date::February, 2019);
    QVERIFY(isDefaultDate(date11));

    Date date12(29, Date::February, 2020);
    QVERIFY(date12.compare(29, Date::February, 2020));

}

void testDate::insertionOperatorTest() {
    {
        Date date(23, Date::October, 2020);
        std::stringstream out;
        out << date;
        QCOMPARE(out.str(), "23/10/2020");
    }

    {
        Date date(7, Date::March, 2020);
        std::stringstream out;
        out << date;
        QCOMPARE(out.str(), "07/03/2020");
    }
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
