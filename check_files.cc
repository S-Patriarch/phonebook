#include "pbook.hh"
#include <fstream>
#include <sys/stat.h>

bool pbook::check_files()
   // функция проверяет служебные файлы, если какого-то файла не
   // оказывается, то она его создает
{
   bool res {true};
   if (_fpb_path!="") {
      const char* ps = _fpb_path.c_str();
      mkdir(ps,0700);
      std::string s = _fpb_path+_fpb;
      std::fstream fs;
      fs.open(s,std::ios::in|std::ios::out|std::ios::app);
      if (!fs.is_open()) {res = false;}
      else {fs.close();}
   }
   return res;
}
