/*
 * Copyright (C) 2024, S-Patriarch.
 *
 * Телефонная книжка.
 * Данный проект реализуется под девизом "Слабоумие и Отвага".
 */

#include "pbook.hh"
#include "other.hh"
#include "pl/color.hh"
#include "pl/conio.hh"

int main()
{
  using std::strncmp;

  PhoneBook pb;

  if (!pb.check_files()) {
    cerr << "E: служебные файлы не прошли проверку" << endl;
    std::exit(EXIT_FAILURE);
  }

  pb.read_phonebook();

  cout << pl::mr::clrscr;
  pb.out_info_logo();

  pl::Color color;
  string enterCommand = enter_command();
  bool isFlageClrScr {true};
  for (;;) {
    if (strncmp("?", enterCommand.c_str(), 1) == 0
      || strncmp("h", enterCommand.c_str(), 1) == 0
      || strncmp("H", enterCommand.c_str(), 1) == 0) {
      cout << pl::mr::clrscr;
      pb.out_info_logo();
      out_info_help();
      isFlageClrScr = false;
    } else if (strncmp("q", enterCommand.c_str(), 1) == 0
      || strncmp("Q", enterCommand.c_str(), 1) == 0) {
      pb.q_phonebook();
      cout << color.esc_tb(pl::Color::color::BLUE) << "W: "
           << color.esc_c()
           << "до новых встреч\n"
           << endl;
      std::exit(EXIT_SUCCESS);
    } else if (strncmp("c", enterCommand.c_str(), 1) == 0
      || strncmp("C", enterCommand.c_str(), 1) == 0) {
      pb.c_phonebook();
      isFlageClrScr = true;
    } else if (strncmp("d", enterCommand.c_str(), 1) == 0
      || strncmp("D", enterCommand.c_str(), 1) == 0) {
      pb.d_phonebook();
      isFlageClrScr = true;
    } else if (strncmp("s", enterCommand.c_str(), 1) == 0
      || strncmp("S", enterCommand.c_str(),1)==0) {
      pb.s_phonebook();
      isFlageClrScr = true;
    } else if (strncmp("p", enterCommand.c_str(), 1) == 0
      || strncmp("P", enterCommand.c_str(), 1) == 0) {
      pb.p_phonebook();
      isFlageClrScr = true;
    }

    if (isFlageClrScr) {
      cout << pl::mr::clrscr;
      pb.out_info_logo();
    }
    enterCommand = enter_command();
  }
}
