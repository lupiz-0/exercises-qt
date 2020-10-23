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
    QCOMPARE(date.day(), 1);
    QCOMPARE(date.month(), Date::January);
    QCOMPARE(date.year(), 1970);
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

QTEST_APPLESS_MAIN(testDate)

#include "tst_date.moc"
