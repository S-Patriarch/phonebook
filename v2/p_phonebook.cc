#include "pbook.hh"
#include "pl/color.hh"
#include "pl/conio.hh"
#include <utility>

void PhoneBook::p_phonebook() const
{
  using mm_t = std::multimap<string, string>;
  mm_t* multimapTemp = new mm_t;

  string subString {};
  cout << "\nподстрока > ";
  std::getline(std::cin, subString);

  // формируем временную хэш-таблицу по запросу
  for (const auto& [k, v] : (*m_phoneBook)) {
    string tempString = k;
    std::size_t position = tempString.find(subString);
    if (position != string::npos) {
      multimapTemp->emplace(std::make_pair(k, v));
    }
  }

  pl::Color color;
  // выводим результат поиска по запросу
  if (!multimapTemp->empty()) {
    cout << endl;
    for (const auto& [k,v] : (*multimapTemp)) {
      cout << color.esc_tb(pl::Color::color::BLUE)
           << "  " << k << '\n'
           << color.esc_c()
           << "  " << v
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

  delete multimapTemp;
  multimapTemp = nullptr;

  pl::Conio conio;
  cout << pl::mr::crsh;
  cout << color.esc_tb(pl::Color::color::BLUE) << "W: "
       << color.esc_c()
       << "нажмите любую клавишу"
       << endl;
  int ch = conio.get_ch();
  cout << pl::mr::crss;
}
