#include "pbook.hh"

void PhoneBook::d_phonebook()
{
  string contact {};
  cout << "\nконтакт > ";
  std::getline(std::cin, contact);

  m_phoneBook->erase(contact);
}
