#include "phonebook.h"

PhoneBook::PhoneBook()
{

}

void PhoneBook::append(const Contact& contact) {
    m_contacts.push_back(contact);
}

const Contact* PhoneBook::find(const std::string& name) {
    for(const Contact& contact: m_contacts) {
        if(contact.name == name)
            return &contact;
    }
    return nullptr;
}
