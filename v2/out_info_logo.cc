#include "pbook.hh"
#include "pl/color.hh"

void PhoneBook::out_info_logo() const
{
  pl::Color color;
  cout << "Телефонная книжка 2.0.0\n"
       << "Для вызова справки введите [?]\n"
       << color.esc_tb(pl::Color::color::BLUE)
       << "Общее количество записей : "
       << m_phoneBook->size()
       << color.esc_c()
       << '\n'
       << endl;
}
