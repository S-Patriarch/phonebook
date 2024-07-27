#include "pbook.hh"
#include <iostream>
#include <string>

void pbook::d_phonebook()
   // функция удаляет контакт
{
   using std::string;

   string s {};
   std::cout << "\ncontact > ";
   std::getline(std::cin,s);

   m_pbht->erase(s);
}
