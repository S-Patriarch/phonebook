#ifndef PBOOK_HH
#define PBOOK_HH

#include <cstdlib>
#include <string>
#include <iostream>
#include <map>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

using multimap_t = std::multimap<string, string>;

class PhoneBook {
  multimap_t* m_phoneBook;
  string m_filePath;
  string m_fileData;
public:
  PhoneBook()
    : m_filePath{}, m_fileData{}
  {
    const char* dir {"HOME"};
    char* dirHome = std::getenv(dir);
    if (dirHome != nullptr) {
      m_filePath = static_cast<string>(dirHome) + "/.pbook";
      m_fileData = m_filePath + "/pbook";
    }
    m_phoneBook = new multimap_t;
  }
  ~PhoneBook() noexcept
  {
    delete m_phoneBook;
    m_phoneBook = nullptr;
  }

  bool check_files() const;
  void out_info_logo() const;
  void read_phonebook() const;
  void q_phonebook() const;
  void s_phonebook() const;
  void p_phonebook() const;
  void c_phonebook();
  void d_phonebook();
};

#endif
