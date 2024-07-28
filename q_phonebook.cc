#include "pbook.hh"
#include <fstream>
#include <string>
#include <iostream>

void PhoneBook::q_phonebook()
   // функция отписывает текущие данные, находящиеся в хэш-таблице, в
   // соответствующий файл данных для хранения
   // структура записи данных, для последующего удобства считывания:
   //    first
   //    second
   //    first
   //    second
   //    ...
{
   std::string fullPath = pbFilePath+pbFile;
   std::fstream fs;
   fs.open(fullPath,std::ios::out);
   for (const auto& p : (*pbHashTable)) {
      fs << p.first << '\n' << p.second << std::endl;
   }
   fs.close();
}
