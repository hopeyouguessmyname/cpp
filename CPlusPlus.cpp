#include <stdio.h>
#include <string>



typedef void( * funkcjaT )(); // wska�nik na funkcj�
void print(std::string function_name, funkcjaT pFunkcja);


int main()
{

  return 0;
}


void print(std::string function_name, funkcjaT pFunkcja)
{
  printf("\n%s\n", function_name.c_str());
  printf("---------------------------------\n");
  pFunkcja();
  printf("---------------------------------\n");
}
