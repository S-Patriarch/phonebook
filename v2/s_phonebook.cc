#include "pbook.hh"
#include "pl/conio.hh"
#include "pl/color.hh"
#include <iterator>

void PhoneBook::s_phonebook() const
{
  string contact {};
  cout << "\nконтакт > ";
  std::getline(std::cin, contact);

  // получаем диапазон итераторов для ключа
  auto rangeIterator = m_phoneBook->equal_range(contact);
  // получаем длину диапазона итераторов
  auto lenghtRange = std::distance(rangeIterator.first, rangeIterator.second);

  pl::Color color;
  if (lenghtRange != 0) {
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
  else {
    cout << color.esc_tb(pl::Color::color::BLUE) << "W: "
         << color.esc_c()
         << "контакт не найден"
         << endl;
  }

  pl::Conio conio;
  cout << pl::mr::crsh;
  cout << color.esc_tb(pl::Color::color::BLUE) << "W: "
       << color.esc_c()
       << "нажмите любую клавишу"
       << endl;
  int ch = conio.get_ch();
  cout << pl::mr::crss;
}
