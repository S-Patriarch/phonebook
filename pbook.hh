// (c) 2024 S-Patriarch
// Описание и инициализация данных : pbook.hh

#ifndef PBOOK_HH
#define PBOOK_HH

#include <cstdlib>
#include <string>
#include <unordered_map>

class pbook {
   using Tm = std::unordered_multimap<std::string,std::string>;

   Tm* _pbht;

   std::string _fpb;       // файл телефонной книжки
   std::string _fpb_path;  // путь к файлу телефонной книжки
public:
   pbook(): _fpb{"/pbook"}
   {
      const char* sh = "HOME";
      char* dir_home = std::getenv(sh);
      if (dir_home==nullptr) {_fpb_path = "";}
      else {_fpb_path = static_cast<std::string>(dir_home)+"/.pbook";}

      _pbht = new Tm;
   }
   ~pbook() noexcept 
   {
      delete _pbht;
      _pbht = nullptr;
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
