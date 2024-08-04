#include "pbook.hh"
#include <utility>

void PhoneBook::c_phonebook()
{
  string contact {};
  string phone {};
  cout << "\nконтакт > ";
  std::getline(std::cin, contact);
  cout << "телефон > ";
  std::getline(std::cin, phone);

  m_phoneBook->emplace(std::make_pair(contact, phone));
}
