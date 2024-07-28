// (c) 2024 S-Patriarch
// Описание и инициализация данных : pbook.hh

#ifndef PBOOK_HH
#define PBOOK_HH

#include <cstdlib>
#include <string>
#include <unordered_map>

class PhoneBook {
   using mm_t = std::unordered_multimap<std::string,std::string>;

   mm_t* pbHashTable;

   std::string pbFile;      // файл телефонной книжки
   std::string pbFilePath;  // путь к файлу телефонной книжки
public:
   PhoneBook()
      : pbFile{"/pbook"}
   {
      const char* dirHome = "HOME";
      char* dir_home = std::getenv(dirHome);
      if (dir_home==nullptr) {pbFilePath = "";}
      else {pbFilePath = static_cast<std::string>(dir_home)+"/.pbook";}

      pbHashTable = new mm_t;
   }
   ~PhoneBook() noexcept
   {
      delete pbHashTable;
      pbHashTable = nullptr;
   }

   void info_logo();
   void info_help();
   void info();
   bool check_files();
   void read_phonebook();
   void q_phonebook();
   void c_phonebook();
   void d_phonebook();
   void s_phonebook();
   void a_phonebook();
   void p_phonebook();
};

#endif  // PBOOK_HH
