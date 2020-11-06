#include <QtTest>
#include <sstream>
#include "../date.h"

// add necessary includes here

class testDate : public QObject {
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
  void addYearsTest();
  void addMonthsTest();
  void addDaysTest();
  void fromStringTest();

 private:
};

char* toString(const Date& date) {
  return QTest::toString(date.toString().c_str());
}

testDate::testDate() {}

testDate::~testDate() {}

void testDate::initTestCase() {}

void testDate::cleanupTestCase() {}

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
  Date dateC(22, Date::October, 2020);
  QVERIFY(!(dateA == dateC));
}

void testDate::addYearsTest() {
  {
    Date date(26, Date::October, 2020);
    date.addYears(13);
    QCOMPARE(date, Date(26, Date::October, 2033));
    date.addYears(-13);
    QCOMPARE(date, Date(26, Date::October, 2020));
    date.addYears(-2021);
    QCOMPARE(date, Date(26, Date::October, 20));
    date.addYears(-19);
    QCOMPARE(date, Date(26, Date::October, 1));
    date.addYears(-2);
    QCOMPARE(date, Date(26, Date::October, 0));
  }

  {
    Date date(26, Date::October, 2020);
    date.addYears(2020);
    QCOMPARE(date, Date(26, Date::October, 4020));
  }

  {
    Date date(29, Date::February, 2020);
    date.addYears(4);
    QCOMPARE(date, Date(29, Date::February, 2024));
  }

  {
    Date date(29, Date::February, 2020);
    date.addYears(3);
    QCOMPARE(date, Date(28, Date::February, 2023));
  }
}

void testDate::addMonthsTest() {
  {
    Date date(26, Date::October, 2020);
    date.addMonths(2);
    QCOMPARE(date, Date(26, Date::December, 2020));
  }

  {
    Date date(26, Date::October, 2020);
    date.addMonths(3 + 12);
    QCOMPARE(date, Date(26, Date::January, 2022));
  }

  {
    Date date(26, Date::October, 2020);
    date.addMonths(4 + 24);
    QCOMPARE(date, Date(26, Date::February, 2023));
  }

  {
    Date date(26, Date::March, 2020);
    date.addMonths(-2);
    QCOMPARE(date, Date(26, Date::January, 2020));
  }

  {
    Date date(26, Date::March, 2020);
    date.addMonths(-3 - 12);
    QCOMPARE(date, Date(26, Date::December, 2018));
  }

  {
    Date date(26, Date::March, 2020);
    date.addMonths(-4 - 24);
    QCOMPARE(date, Date(26, Date::November, 2017));
  }

  {
    Date date(31, Date::March, 2020);
    date.addMonths(-1);
    QCOMPARE(date, Date(29, Date::February, 2020));
  }

  {
    Date date(31, Date::March, 2020);
    date.addMonths(+1);
    QCOMPARE(date, Date(30, Date::April, 2020));
  }

  {
    Date date(29, Date::February, 2020);
    date.addMonths(+1);
    QCOMPARE(date, Date(29, Date::March, 2020));
  }

  {
    Date date(29, Date::February, 2020);
    date.addMonths(-1);
    QCOMPARE(date, Date(29, Date::January, 2020));
  }

  {
    Date date(28, Date::February, 2020);
    date.addMonths(-12);
    QCOMPARE(date, Date(28, Date::February, 2019));
  }

  {
    Date date(28, Date::February, 2020);
    date.addMonths(+12);
    QCOMPARE(date, Date(28, Date::February, 2021));
  }

  {
    Date date(29, Date::February, 2020);
    date.addMonths(48);
    QCOMPARE(date, Date(29, Date::February, 2024));
  }

  {
    Date date(29, Date::February, 2020);
    date.addMonths(-48);
    QCOMPARE(date, Date(29, Date::February, 2016));
  }
}

/*!
 * results of the tests taken from https://www.timeanddate.com/date/dateadd.html
 */
void testDate::addDaysTest() {
  {
    Date date(28, 10, 2020);
    date.addDays(-1596);
    Date result(15, Date::June, 2016);
    QCOMPARE(date, result);
  }

  {
    Date date(28, 10, 2020);
    date.addDays(18240);
    Date result(6, Date::October, 2070);
    QCOMPARE(date, result);
  }

  {
    Date date(28, 10, 2020);
    date.addDays(9357);
    Date result(11, Date::June, 2046);
    QCOMPARE(date, result);
  }

  {
    Date date(28, 10, 2020);
    date.addDays(-27493);
    Date result(21, Date::July, 1945);
    QCOMPARE(date, result);
  }

  {
    Date date(29, 2, 2020);
    date.addDays(-365);
    Date result(1, Date::March, 2019);
    QCOMPARE(date, result);
  }

  {
    Date date(31, Date::March, 2020);
    date.addDays(365 * 2 + 30);
    Date result(30, Date::April, 2022);
    QCOMPARE(date, result);
  }

  {
    Date date(29, 2, 2020);
    date.addDays(365 * 2);
    Date result(28, Date::February, 2022);
    QCOMPARE(date, result);
  }

  {
    Date date(28, 2, 2019);
    date.addDays(366);
    Date result(29, Date::February, 2020);
    QCOMPARE(date, result);
  }

  {
    Date date(28, 2, 2022);
    date.addDays(-730);
    Date result(29, Date::February, 2020);
    QCOMPARE(date, result);
  }
}

void testDate::fromStringTest() {
  QCOMPARE(Date::fromString("28-10-2020"), Date(28, 10, 2020));

  QCOMPARE(Date::fromString("08-10-2020"), Date(8, 10, 2020));
  QCOMPARE(Date::fromString("28-07-2020"), Date(28, 7, 2020));
  QCOMPARE(Date::fromString("28-07-0020"), Date(28, 7, 20));

  QCOMPARE(Date::fromString("a2-10-2020"), Date());
  QCOMPARE(Date::fromString("28-1a-2020"), Date());
  QCOMPARE(Date::fromString("28-10-20a0"), Date());
  QCOMPARE(Date::fromString("28-10-2.20"), Date());

  QCOMPARE(Date::fromString("28-10-020"), Date());
  QCOMPARE(Date::fromString("28-1-2020"), Date());
  QCOMPARE(Date::fromString("8-10-2020"), Date());

  QCOMPARE(Date::fromString("28-10-2020-20"), Date());
  QCOMPARE(Date::fromString("28--1020"), Date());

  QCOMPARE(Date::fromString("29-02-2020"), Date(29, 2, 2020));
  QCOMPARE(Date::fromString("29-02-2021"), Date());
  QCOMPARE(Date::fromString("31-04-2020"), Date());

  QCOMPARE(Date::fromString("28- 7-2020"), Date());
  QCOMPARE(Date::fromString("28-10-  20"), Date());
  QCOMPARE(Date::fromString("28-10-2 20"), Date());
  QCOMPARE(Date::fromString(" 8-10-2020"), Date());
  QCOMPARE(Date::fromString("28-10-202 "), Date());
}

QTEST_APPLESS_MAIN(testDate)

#include "tst_date.moc"
