#include "pbook.hh"
#include <fstream>
#include <string>
#include <iostream>

void pbook::q_phonebook()
   // функция отписывает текущие данные, находящиеся в хэш-таблице, в
   // соответствующий файл данных для хранения
   // структура записи данных, для последующего удобства считывания:
   //    first
   //    second
   //    first
   //    second
   //    ...
{
   std::string s = _fpb_path+_fpb;
   std::fstream fs;
   fs.open(s,std::ios::out);
   for (const auto& p : (*_pbht)) {
      fs << p.first << '\n' << p.second << std::endl;
   }
   fs.close();
}
