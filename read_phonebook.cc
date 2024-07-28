#include "pbook.hh"
#include <fstream>
#include <string>
#include <iostream>

void PhoneBook::read_phonebook()
   // функция чтения контактов из файла данных в хэш-таблицу
{
   using std::string;

   string fullPath = pbFilePath+pbFile;
   std::fstream fs;
   fs.open(fullPath,std::ios::in);

   // проверяем файл на наличие данных
   // если файл оказался пустым, то закрываем его, поскольку
   // считывать нечего
   fs.seekg(0,std::ios::end);
   if (fs.tellg()!=0) {
      fs.seekg(0,std::ios::beg);
      string key {};
      string value {};
      while (!fs.eof()) {
         std::getline(fs,key);
         if (key=="") {break;}
         std::getline(fs,value);
         pbHashTable->emplace(key,value);
      }
   }
   fs.close();
}
