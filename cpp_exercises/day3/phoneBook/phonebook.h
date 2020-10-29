#pragma once

#include <string>
#include <vector>

struct Contact {
  std::string name;
  std::string surname;
  std::string telephoneNumber;
};

class PhoneBook
{
public:
    PhoneBook();

    void append(const Contact& contact);
    Contact* find(const std::string& name);

    friend std::ostream& operator<<(std::ostream& ostream, const PhoneBook& phoneBook);

private:
    std::vector<Contact> m_contacts;
};

std::ostream& operator<<(std::ostream& ostream, const PhoneBook& phoneBook);
