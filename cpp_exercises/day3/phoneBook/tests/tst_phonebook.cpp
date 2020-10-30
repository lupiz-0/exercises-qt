#include <QtTest>
#include <sstream>
#include "../phonebook.h"

class RangeFilter: public PhoneBookPassFiter {

public:
    RangeFilter(int max_id): m_max_id(max_id){};
    bool pass() override{
        return m_id <= m_max_id;
    };

private:
    int m_max_id;
};
class testPhoneBook : public QObject
{
    Q_OBJECT

public:
    testPhoneBook();
    ~testPhoneBook();

private slots:
    bool haveContact(const std::vector<Contact*>& contacts, const Contact& toCheck);
    void initTestCase();
    void cleanupTestCase();
    void findTest();
    void insertionOperatorTest();

private:
    void fill(PhoneBook& phoneBook);
    void filterTest();
};

bool testPhoneBook::haveContact(const std::vector<Contact*>& contacts, const Contact& toCheck) {
    for(const Contact* contact: contacts) {
        if(*contact == toCheck)
            return true;
    }
    return false;
}

void testPhoneBook::fill(PhoneBook& phoneBook) {
    phoneBook.append(Contact{"Gerry", "Calà", "+39 0123456789"});
    phoneBook.append(Contact{"Alberto", "Sordi", "+38 111222333"});
    phoneBook.append(Contact{"Bud", "Spencer", "+39 20202020"});
    phoneBook.append(Contact{"Albano", "Carrisi", "+39 444333444"});
}

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
    fill(phoneBook);

    const Contact* contact = phoneBook.find("Gerry");
    QVERIFY(contact);
    QCOMPARE(contact->name, "Gerry");
    QCOMPARE(contact->surname, "Calà");
    QCOMPARE(contact->telephoneNumber, "+39 0123456789");

    contact = phoneBook.find("Alberto");
    QVERIFY(contact);
    QCOMPARE(contact->name, "Alberto");
    QCOMPARE(contact->surname, "Sordi");
    QCOMPARE(contact->telephoneNumber, "+38 111222333");

    contact = phoneBook.find("Bud");
    QVERIFY(contact);
    QCOMPARE(contact->name, "Bud");
    QCOMPARE(contact->surname, "Spencer");
    QCOMPARE(contact->telephoneNumber, "+39 20202020");

    contact = phoneBook.find("Sordi");
    QCOMPARE(contact, nullptr);
}

void testPhoneBook::insertionOperatorTest() {
    PhoneBook phoneBook;
    fill(phoneBook);

    std::stringstream out;
    out << phoneBook;
    const char* resultExpected = "1) Calà Gerry\n"
                                 "   tel: +39 0123456789\n"
                                 "2) Sordi Alberto\n"
                                 "   tel: +38 111222333\n"
                                 "3) Spencer Bud\n"
                                 "   tel: +39 20202020\n"
                                 "4) Carrisi Albano\n"
                                 "   tel: +39 444333444\n";
    QCOMPARE(out.str(), resultExpected);
}


void testPhoneBook::filterTest() {
    PhoneBook phoneBook;
    fill(phoneBook);

    {
        RangeFilter filter(1);
        std::vector<Contact*> contacts = phoneBook.filter(&filter);
        QVERIFY(haveContact(contacts, Contact{"Gerry", "Calà", "+39 0123456789"}));
        QVERIFY(haveContact(contacts, Contact{"Alberto", "Sordi", "+38 111222333"}));
        QCOMPARE(haveContact(contacts, Contact{"Bud", "Spencer", "+39 20202020"}), false);
        QCOMPARE(haveContact(contacts, Contact{"Albano", "Carrisi", "+39 444333444"}), false);
    }
}

QTEST_APPLESS_MAIN(testPhoneBook)

#include "tst_phonebook.moc"
