#include <QtTest>
 #include "../phonebook.h"

// add necessary includes here

class testPhoneBook : public QObject
{
    Q_OBJECT

public:
    testPhoneBook();
    ~testPhoneBook();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

testPhoneBook::testPhoneBook()
{

}

testPhoneBook::~testPhoneBook()
{

}

void testPhoneBook::initTestCase()
{

}

void testPhoneBook::cleanupTestCase()
{

}

void testPhoneBook::test_case1()
{

}

QTEST_APPLESS_MAIN(testPhoneBook)

#include "tst_phonebook.moc"
