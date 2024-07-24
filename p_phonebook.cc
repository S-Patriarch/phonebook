#include "pbook.hh"
#include "pl/color.hh"
#include "pl/conio.hh"
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>

void pbook::p_phonebook()
   // функция осуществляет поиск контакта по подстроке
   // алгоритмическая сложность O(n)
{
   using std::string;
   using std::cout;
   using std::endl;

   // создаем временную хэш-таблицу в куче
   std::unordered_multimap<string,string>* mm;
   mm = new std::unordered_multimap<string,string>;

   string s {};
   cout << "\ncontact > ";
   std::getline(std::cin,s);

   // формируем временную хэш-таблицу по запросу
   for (const auto& [key,value] : (*_pbht)) {
      string stmp = key;
      std::size_t pos = stmp.find(s);
      if (pos!=string::npos) {
         mm->emplace(std::make_pair(key,value));
      }
   }
   // выводим результат поиска по запросу
   if (!mm->empty()) {
      pl::Color color;
      cout << endl;
      for (const auto& [key,value] : (*mm)) {
         cout << color.esc_tb(pl::Color::color::BLUE)
              << key << '\n'
              << color.esc_c()
              << value
              << endl;
      }
      cout << endl;
   }
   else {cout << "\nW: contact not found" << endl;}

   delete mm;

   pl::Conio conio;
   cout << pl::mr::crsh;
   cout << "W: press any key" << endl;
   int ch = conio.get_ch();
   cout << pl::mr::crss;
}
