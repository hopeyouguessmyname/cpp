#include <stdio.h>
#include <string>

#include "functions.h"


typedef void( * funkcjaT )(); // wskaŸnik na funkcjê
void print(std::string function_name, funkcjaT pFunkcja);


int main()
{
  print("_011_const", _011_const);
  print("_012_const", _012_const);
  print("_013_const", _013_const);
  
  return 0;
}


void print(std::string function_name, funkcjaT pFunkcja)
{
  printf("\n%s\n", function_name.c_str());
  printf("---------------------------------\n");
  pFunkcja();
  printf("---------------------------------\n");
}
