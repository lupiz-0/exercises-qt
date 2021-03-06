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

class NameStartsWithFilter: public PhoneBookPassFiter {

public:
    NameStartsWithFilter(const std::string& startingString): m_startingString(startingString){};
    bool pass() override{
        return !m_contact->name.compare(0, m_startingString.size(), m_startingString);
    };

private:
    std::string m_startingString;
};

class ItalianNumberFilter: public PhoneBookPassFiter {

public:
    bool pass() override{
        const std::string startingString = "+39";
        return !m_contact->telephoneNumber.compare(0, startingString.size(), startingString);
    };
};

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
    void insertionOperatorTest();
    void filterTest();

private:
    void fill(PhoneBook& phoneBook);
    bool haveContact(const std::vector<Contact*>& contacts, const Contact& toCheck);
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
    const char* resultExpected = R"(1) Calà Gerry
   tel: +39 0123456789
2) Sordi Alberto
   tel: +38 111222333
3) Spencer Bud
   tel: +39 20202020
4) Carrisi Albano
   tel: +39 444333444
)";
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
        QVERIFY(!haveContact(contacts, Contact{"Bud", "Spencer", "+39 20202020"}));
        QVERIFY(!haveContact(contacts, Contact{"Albano", "Carrisi", "+39 444333444"}));
    }

    {
        NameStartsWithFilter filter("Alb");
        std::vector<Contact*> contacts = phoneBook.filter(&filter);
        QVERIFY(haveContact(contacts, Contact{"Alberto", "Sordi", "+38 111222333"}));
        QVERIFY(haveContact(contacts, Contact{"Albano", "Carrisi", "+39 444333444"}));
        QVERIFY(!haveContact(contacts, Contact{"Gerry", "Calà", "+39 0123456789"}));
        QVERIFY(!haveContact(contacts, Contact{"Bud", "Spencer", "+39 20202020"}));
    }

    {
        ItalianNumberFilter filter;
        std::vector<Contact*> contacts = phoneBook.filter(&filter);
        QVERIFY(!haveContact(contacts, Contact{"Alberto", "Sordi", "+38 111222333"}));
        QVERIFY(haveContact(contacts, Contact{"Albano", "Carrisi", "+39 444333444"}));
        QVERIFY(haveContact(contacts, Contact{"Gerry", "Calà", "+39 0123456789"}));
        QVERIFY(haveContact(contacts, Contact{"Bud", "Spencer", "+39 20202020"}));
    }
}

QTEST_APPLESS_MAIN(testPhoneBook)

#include "tst_phonebook.moc"
