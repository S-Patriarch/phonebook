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
   std::string s = m_fpb_path+m_fpb;
   std::fstream fs;
   fs.open(s,std::ios::out);
   for (const auto& p : (*m_pbht)) {
      fs << p.first << '\n' << p.second << std::endl;
   }
   fs.close();
}
