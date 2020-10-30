#include "phonebook.h"
#include <algorithm>

PhoneBook::PhoneBook()
{

}

void PhoneBook::append(const Contact& contact) {
    m_contacts.push_back(contact);
}

const Contact* PhoneBook::find(const std::string& name) {
    std::vector<Contact>::iterator it = std::find_if (m_contacts.begin(), m_contacts.end(), [name](const Contact& contact){
        return contact.name == name;
    });

    if(it == m_contacts.end())
        return nullptr;

    return &(*it);
}
