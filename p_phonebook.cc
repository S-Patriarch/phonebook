#include "pbook.hh"
#include "pl/color.hh"
#include "pl/conio.hh"
#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>

void PhoneBook::p_phonebook()
   // функция осуществляет поиск контакта по подстроке
   // алгоритмическая сложность O(n)
{
   using mm_t = std::unordered_multimap<std::string,std::string>;

   using std::string;
   using std::cout;
   using std::endl;

   // создаем временную хэш-таблицу в куче
   mm_t* tempHashTable = new mm_t;

   string subString {};
   cout << "\nsubstring > ";
   std::getline(std::cin,subString);

   // формируем временную хэш-таблицу по запросу
   for (const auto& [k,v] : (*pbHashTable)) {
      string tempString = k;
      std::size_t position = tempString.find(subString);
      if (position!=string::npos) {
         tempHashTable->emplace(std::make_pair(k,v));
      }
   }
   // выводим результат поиска по запросу
   if (!tempHashTable->empty()) {
      pl::Color color;
      cout << endl;
      for (const auto& [k,v] : (*tempHashTable)) {
         cout << color.esc_tb(pl::Color::color::BLUE)
              << "  " << k << '\n'
              << color.esc_c()
              << "  " << v
              << endl;
      }
      cout << endl;
   }
   else {cout << "\nW: contact not found" << endl;}

   delete tempHashTable;
   tempHashTable = nullptr;

   pl::Conio conio;
   cout << pl::mr::crsh;
   cout << "W: press any key" << endl;
   int ch = conio.get_ch();
   cout << pl::mr::crss;
}
