//
// (c) 2024 S-Patriarch
//
// Телефонная книжка.
// Версия проекта 1.0.0
// Данный проект реализуется под девизом "Слабоумие и Отвага".
//

#include "pbook.hh"
#include "pl/conio.hh"
#include <iostream>
////////////////////////////////////////////////////////////////////////////////
int main()
{
   using std::cout;
   using std::cerr;
   using std::endl;
   using std::string;
   using std::strncmp;
   using std::make_pair;

   pl::Conio conio;
   pbook pbd;

   if (!pbd.check_files()) {
      cerr << "E: service file check failed" << endl;
      std::exit(EXIT_FAILURE);
   }
   pbd.read_phonebook();

   cout << pl::mr::clrscr;
   pbd.info();

   string s {};
   s = conio.get_line(3);
   for (;;) {
      if (strncmp("q",s.c_str(),1)==0 || strncmp("Q",s.c_str(),1)==0) {
         pbd.q_phonebook();
         cout << "\nW: until next time\n" << endl;
         std::exit(EXIT_SUCCESS);
      }
      if (strncmp("c",s.c_str(),1)==0 || strncmp("C",s.c_str(),1)==0) {
         pbd.c_phonebook();
      }
      if (strncmp("d",s.c_str(),1)==0 || strncmp("D",s.c_str(),1)==0) {
         pbd.d_phonebook();
      }
      if (strncmp("s",s.c_str(),1)==0 || strncmp("S",s.c_str(),1)==0) {
         pbd.s_phonebook();
      }
      if (strncmp("a",s.c_str(),1)==0 || strncmp("A",s.c_str(),1)==0) {
         pbd.a_phonebook();
      }

      cout << pl::mr::clrscr;
      pbd.info();
      s = conio.get_line(3);
   }
}
