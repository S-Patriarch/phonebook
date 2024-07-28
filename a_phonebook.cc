#include "pbook.hh"
#include "pl/conio.hh"
#include "pl/color.hh"
#include <iostream>

void PhoneBook::a_phonebook()
   // функция выводит все контакты
{
   using std::cout;
   using std::endl;

   pl::Color color;

   cout << endl;
   for (const auto& [k,v] : (*pbHashTable)) {
      cout << color.esc_tb(pl::Color::color::BLUE)
           << "  " << k << '\n'
           << color.esc_c()
           << "  " << v << '\n';
   }

   pl::Conio conio;
   cout << pl::mr::crsh;
   cout << "\nW: press any key" << endl;
   int ch = conio.get_ch();
   cout << pl::mr::crss;
}
