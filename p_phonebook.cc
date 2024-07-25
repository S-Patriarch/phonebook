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
   using Tm = std::unordered_multimap<std::string,std::string>;

   using std::string;
   using std::cout;
   using std::endl;

   // создаем временную хэш-таблицу в куче
   Tm* mm = new Tm;

   string s {};
   cout << "\nsubstring > ";
   std::getline(std::cin,s);

   // формируем временную хэш-таблицу по запросу
   for (const auto& [k,v] : (*_pbht)) {
      string stmp = k;
      std::size_t pos = stmp.find(s);
      if (pos!=string::npos) {
         mm->emplace(std::make_pair(k,v));
      }
   }
   // выводим результат поиска по запросу
   if (!mm->empty()) {
      pl::Color color;
      cout << endl;
      for (const auto& [k,v] : (*mm)) {
         cout << color.esc_tb(pl::Color::color::BLUE)
              << "  " << k << '\n'
              << color.esc_c()
              << "  " << v
              << endl;
      }
      cout << endl;
   }
   else {cout << "\nW: contact not found" << endl;}

   delete mm;
   mm = nullptr;

   pl::Conio conio;
   cout << pl::mr::crsh;
   cout << "W: press any key" << endl;
   int ch = conio.get_ch();
   cout << pl::mr::crss;
}
