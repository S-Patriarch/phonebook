#include "pbook.hh"
#include "pl/conio.hh"
#include "pl/color.hh"
#include <iostream>

void pbook::a_phonebook()
   // функция выводит все контакты
{
   using std::cout;
   using std::endl;

   pl::Color color;

   cout << endl;
   for (const auto& [key,value] : (*_pbht)) {
      cout << color.esc_tb(pl::Color::color::BLUE)
           << key << '\n'
           << color.esc_c()
           << value << '\n';
   }

   pl::Conio conio;
   cout << pl::mr::crsh;
   cout << "\nW: press any key" << endl;
   int ch = conio.get_ch();
   cout << pl::mr::crss;
}
