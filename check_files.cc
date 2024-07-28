#include "pbook.hh"
#include <fstream>
#include <sys/stat.h>

bool PhoneBook::check_files()
   // функция проверяет служебные файлы, если какого-то файла не
   // оказывается, то она его создает
{
   bool result {true};
   if (pbFilePath!="") {
      const char* directoryPath = pbFilePath.c_str();
      mkdir(directoryPath,0700);
      std::string fullPath = pbFilePath+pbFile;
      std::fstream fs;
      fs.open(fullPath,std::ios::in|std::ios::out|std::ios::app);
      if (!fs.is_open()) {result = false;}
      else {fs.close();}
   }
   return result;
}
