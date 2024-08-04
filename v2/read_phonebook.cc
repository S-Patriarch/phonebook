#include "pbook.hh"
#include <fstream>

void PhoneBook::read_phonebook() const
{
  std::fstream fs;
  fs.open(m_fileData, std::ios::in);

  // проверяем файл на наличие данных
  // если файл оказался пустым, то закрываем его, поскольку
  // считывать нечего
  fs.seekg(0, std::ios::end);
  if (fs.tellg() != 0) {
    fs.seekg(0, std::ios::beg);
    string key {};
    string value {};
    while (!fs.eof()) {
      std::getline(fs, key);
      if (key == "") break;
      std::getline(fs, value);
      m_phoneBook->emplace(key, value);
    }
  }
  fs.close();
}
