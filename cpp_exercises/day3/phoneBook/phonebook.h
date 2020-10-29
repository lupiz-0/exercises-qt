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

private:
    std::vector<Contact> m_contacts;
};

