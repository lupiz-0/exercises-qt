#include "phonebook.h"
#include <algorithm>
#include <ostream>

PhoneBook::PhoneBook()
{

}

void PhoneBook::append(const Contact& contact) {
    m_contacts.push_back(contact);
}

Contact* PhoneBook::find(const std::string& name) {
    std::vector<Contact>::iterator it = std::find_if (m_contacts.begin(), m_contacts.end(), [name](const Contact& contact){
        return contact.name == name;
    });

    if(it == m_contacts.end())
        return nullptr;

    return &(*it);
}

std::ostream& operator<<(std::ostream& ostream, const PhoneBook& phoneBook) {
    int id = 0;
    std::for_each(phoneBook.m_contacts.begin(), phoneBook.m_contacts.end(), [&ostream, &id](const Contact& contact) {
        ostream << id + 1 << ") " << contact.surname << ' ' << contact.name << '\n';
        ostream << "   tel: " << contact.telephoneNumber << '\n';
        id++;
    });
    return ostream;
}
