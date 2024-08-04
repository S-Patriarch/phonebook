#include "pbook.hh"
#include <fstream>

void PhoneBook::q_phonebook() const
{
  std::fstream fs;
  fs.open(m_fileData, std::ios::out);
  for (const auto& p : (*m_phoneBook)) {
    fs << p.first << '\n' << p.second << endl;
  }
  fs.close();
}
