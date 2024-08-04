#include "other.hh"
#include "pl/conio.hh"

string enter_command()
{
  pl::Conio conio;
  cout << "> ";
  return conio.get_line(3);
}
