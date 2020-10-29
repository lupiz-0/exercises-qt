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
    void findTest();

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

void testPhoneBook::findTest()
{
    PhoneBook phoneBook;
    phoneBook.append(Contact{"Gerry", "Calà", "+39 0123456789"});
    phoneBook.append(Contact{"Alberto", "Sordi", "+39 111222333"});
    phoneBook.append(Contact{"Bud", "Spencer", "+39 20202020"});

    const Contact* contact = phoneBook.find("Gerry");
    QVERIFY(contact);
    QCOMPARE(contact->name, "Gerry");
    QCOMPARE(contact->surname, "Calà");
    QCOMPARE(contact->telephoneNumber, "+39 0123456789");

    contact = phoneBook.find("Alberto");
    QVERIFY(contact);
    QCOMPARE(contact->name, "Alberto");
    QCOMPARE(contact->surname, "Sordi");
    QCOMPARE(contact->telephoneNumber, "+39 111222333");

    contact = phoneBook.find("Bud");
    QVERIFY(contact);
    QCOMPARE(contact->name, "Bud");
    QCOMPARE(contact->surname, "Spencer");
    QCOMPARE(contact->telephoneNumber, "+39 20202020");

    contact = phoneBook.find("Sordi");
    QCOMPARE(contact, nullptr);
}

QTEST_APPLESS_MAIN(testPhoneBook)

#include "tst_phonebook.moc"
