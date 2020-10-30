#pragma once

#include <string>
#include <vector>

struct Contact {
  std::string name;
  std::string surname;
  std::string telephoneNumber;
};

class PhoneBookPassFiter {

public:
    void setContact(Contact& contact) {m_contact = &contact;};
    void setId(int id){m_id = id;};
    virtual bool pass() = 0;

protected:
    Contact* m_contact;
    int m_id;
};


class PhoneBook
{
public:
    PhoneBook();
    void append(const Contact& contact);
    Contact* find(const std::string& name);
    std::vector<Contact*> filter(PhoneBookPassFiter* passFilter);

    friend std::ostream& operator<<(std::ostream& ostream, const PhoneBook& phoneBook);

private:
    std::vector<Contact> m_contacts;
};

std::ostream& operator<<(std::ostream& ostream, const PhoneBook& phoneBook);
