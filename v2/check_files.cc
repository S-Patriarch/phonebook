#include "pbook.hh"
#include <fstream>
#include <sys/stat.h>

bool PhoneBook::check_files() const
{
  if (m_filePath == "") {
    return false;
  } else {
    const char* dirPath = m_filePath.c_str();
    mkdir(dirPath, 0700);

    std::fstream fs;
    fs.open(m_fileData, std::ios::in|std::ios::out|std::ios::app);
    if (!fs.is_open()) return false;
    else fs.close();
  }
  return true;
}
