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
    Date defaultDate;

    Date date0(26, Date::October, 2020);
    QCOMPARE(date0.day(), 26);
    QCOMPARE(date0.month(), Date::October);
    QCOMPARE(date0.year(), 2020);

    Date date1(26, Date::October, -1);
    QCOMPARE(date1, defaultDate);

    Date date2(26, Date::October, 0);
    QCOMPARE(date2.day(), 26);
    QCOMPARE(date2.month(), Date::October);
    QCOMPARE(date2.year(), 0);

    Date date3(26, 0, 2020);
    QCOMPARE(date3, defaultDate);

    Date date4(26, 1, 2020);
    QCOMPARE(date4.day(), 26);
    QCOMPARE(date4.month(), 1);
    QCOMPARE(date4.year(), 2020);

    Date date5(26, 13, 2020);
    QCOMPARE(date5, defaultDate);

    Date date6(26, 12, 2020);
    QCOMPARE(date6.day(), 26);
    QCOMPARE(date6.month(), 12);
    QCOMPARE(date6.year(), 2020);

    Date date7(1, Date::November, 2020);
    QCOMPARE(date7.day(), 1);
    QCOMPARE(date7.month(), Date::November);
    QCOMPARE(date7.year(), 2020);

    Date date8(0, Date::November, 2020);
    QCOMPARE(date8, defaultDate);

    Date date9(30, Date::November, 2020);
    QCOMPARE(date9.day(), 30);
    QCOMPARE(date9.month(), Date::November);
    QCOMPARE(date9.year(), 2020);

    Date date10(31, Date::November, 2020);
    QCOMPARE(date10, defaultDate);

    Date date11(29, Date::February, 2019);
    QCOMPARE(date11, defaultDate);

    Date date12(29, Date::February, 2020);
    QCOMPARE(date12.day(), 29);
    QCOMPARE(date12.month(), Date::February);
    QCOMPARE(date12.year(), 2020);
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

QTEST_APPLESS_MAIN(testDate)

#include "tst_date.moc"