#include "pbook.hh"
#include <iostream>
#include <string>

void PhoneBook::d_phonebook()
   // функция удаляет контакт
{
   using std::string;

   string contact {};
   std::cout << "\ncontact > ";
   std::getline(std::cin,contact);

   pbHashTable->erase(contact);
}
