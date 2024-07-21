#include "pbook.hh"
#include "pl/conio.hh"
#include "pl/color.hh"
#include <iostream>
#include <string>

void pbook::s_phonebook()
   // функция осуществляет поиск контакта
{
   using std::string;
   using std::cout;
   using std::endl;

   string s {};
   cout << "\ncontact > ";
   std::getline(std::cin,s);

   // получаем диапазон итераторов для ключа
   auto range = _pbht->equal_range(s);
   // получаем длину диапазона итераторов
   auto len = std::distance(range.first, range.second);

   if (len!=0) {
      pl::Color color;
      cout << endl;
      // выводим все совпадения
      for (auto it=range.first; it!=range.second; ++it) {
         cout << color.esc_tb(pl::Color::color::BLUE)
              << it->first << '\n'
              << color.esc_c()
              << it->second
              << endl;
      }
      cout << endl;
   }
   else {cout << "\nW: contact not found" << endl;}

   pl::Conio conio;
   cout << pl::mr::crsh;
   cout << "W: press any key" << endl;
   int ch = conio.get_ch();
   cout << pl::mr::crss;
}
