#include "pbook.hh"
#include <iostream>

void pbook::info_help()
   // выводит информационную подсказку
{
   std::cout << "Commands:\n"
             << "  a - display all contacts\n"
             << "  s - search for contact\n"
             << "  c - create a new contact\n"
             << "  d - delete contact\n"
             << "  q - exit\n"
             << std::endl;
}
