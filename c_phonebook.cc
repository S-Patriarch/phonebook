#include "pbook.hh"
#include <iostream>
#include <string>
#include <utility>

void PhoneBook::c_phonebook()
   // функция создает новый контакт
{
   using std::string;

   string contact {};
   string phone {};
   std::cout << "\ncontact > ";
   std::getline(std::cin,contact);
   std::cout << "phone   > ";
   std::getline(std::cin,phone);

   pbHashTable->emplace(std::make_pair(contact,phone));
}
