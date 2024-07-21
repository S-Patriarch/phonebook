#include "pbook.hh"
#include <iostream>
#include <string>
#include <utility>

void pbook::c_phonebook()
   // функция создает новый контакт
{
   using std::string;

   string s1 {};
   string s2 {};
   std::cout << "\ncontact > ";
   std::getline(std::cin,s1);
   std::cout << "phone   > ";
   std::getline(std::cin,s2);

   _pbht->emplace(std::make_pair(s1,s2));
}
