// (c) 2024 S-Patriarch
// Описание и инициализация данных : pbook.hh

#ifndef PBOOK_HH
#define PBOOK_HH

#include <cstdlib>
#include <string>
#include <unordered_map>

class pbook {
   using mm_t = std::unordered_multimap<std::string,std::string>;

   mm_t* m_pbht;

   std::string m_fpb;       // файл телефонной книжки
   std::string m_fpb_path;  // путь к файлу телефонной книжки
public:
   pbook()
      : m_fpb{"/pbook"}
   {
      const char* sh = "HOME";
      char* dir_home = std::getenv(sh);
      if (dir_home==nullptr) {m_fpb_path = "";}
      else {m_fpb_path = static_cast<std::string>(dir_home)+"/.pbook";}

      m_pbht = new mm_t;
   }
   ~pbook() noexcept 
   {
      delete m_pbht;
      m_pbht = nullptr;
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
