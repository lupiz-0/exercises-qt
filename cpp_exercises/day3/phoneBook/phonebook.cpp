#include "phonebook.h"

PhoneBook::PhoneBook()
{

}

void PhoneBook::append(const Contact& contact) {
    m_contacts.push_back(contact);
}