//
// (c) 2024 S-Patriarch
// Телефонная книжка.
// Данный проект реализуется под девизом "Слабоумие и Отвага".
//------------------------------------------------------------------------------
#include "pbook.hh"
#include "pl/conio.hh"
#include <iostream>

int main()
{
   using std::cout;
   using std::cerr;
   using std::endl;
   using std::string;
   using std::strncmp;
   using std::make_pair;

   pl::Conio conio;
   PhoneBook pb;

   if (!pb.check_files()) {
      cerr << "E: service file check failed" << endl;
      std::exit(EXIT_FAILURE);
   }
   pb.read_phonebook();

   cout << pl::mr::clrscr;
   pb.info();

   string sLine {};
   sLine = conio.get_line(3);
   for (;;) {
      if (strncmp("q",sLine.c_str(),1)==0 || strncmp("Q",sLine.c_str(),1)==0) {
         pb.q_phonebook();
         cout << "\nW: until next time\n" << endl;
         std::exit(EXIT_SUCCESS);
      }
      if (strncmp("c",sLine.c_str(),1)==0 || strncmp("C",sLine.c_str(),1)==0) {
         pb.c_phonebook();
      }
      if (strncmp("d",sLine.c_str(),1)==0 || strncmp("D",sLine.c_str(),1)==0) {
         pb.d_phonebook();
      }
      if (strncmp("s",sLine.c_str(),1)==0 || strncmp("S",sLine.c_str(),1)==0) {
         pb.s_phonebook();
      }
      if (strncmp("a",sLine.c_str(),1)==0 || strncmp("A",sLine.c_str(),1)==0) {
         pb.a_phonebook();
      }
      if (strncmp("p",sLine.c_str(),1)==0 || strncmp("P",sLine.c_str(),1)==0) {
         pb.p_phonebook();
      }

      cout << pl::mr::clrscr;
      pb.info();
      sLine = conio.get_line(3);
   }
}
