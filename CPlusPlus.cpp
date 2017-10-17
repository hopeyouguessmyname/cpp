#include <stdio.h>
#include <string>

#include "functions.h"


typedef void( * funkcjaT )(); // wskaŸnik na funkcjê
void print(std::string function_name, funkcjaT pFunkcja);


int main()
{
//  print("_011_const", _011_const);
//  print("_012_const", _012_const);
//  print("_013_const", _013_const);
//  print("_015_static", _015_static);
//  print("_021_inline", _021_inline);
//  print("_022_inline", _022_inline);
//  print("_023_inline", _023_inline);
  print("_031_virtual", _031_virtual);
  print("_032_virtual", _032_virtual);
  print("_035_virtual", _035_virtual);
  
  return 0;
}


void print(std::string function_name, funkcjaT pFunkcja)
{
  printf("\n%s\n", function_name.c_str());
  printf("---------------------------------\n");
  pFunkcja();
  printf("---------------------------------\n");
}
