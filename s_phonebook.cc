#include "pbook.hh"
#include "pl/conio.hh"
#include "pl/color.hh"
#include <iostream>
#include <string>
#include <iterator>

void PhoneBook::s_phonebook()
   // функция осуществляет поиск контакта
   // алгоритмическая сложность O(1)
{
   using std::string;
   using std::cout;
   using std::endl;

   string contact {};
   cout << "\ncontact > ";
   std::getline(std::cin,contact);

   // получаем диапазон итераторов для ключа
   auto rangeIterator = pbHashTable->equal_range(contact);
   // получаем длину диапазона итераторов
   auto lenghtRange = std::distance(rangeIterator.first, rangeIterator.second);

   if (lenghtRange!=0) {
      pl::Color color;
      cout << endl;
      // выводим все совпадения
      for (auto i=rangeIterator.first; i!=rangeIterator.second; ++i) {
         cout << color.esc_tb(pl::Color::color::BLUE)
              << "  " << i->first << '\n'
              << color.esc_c()
              << "  " << i->second
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
