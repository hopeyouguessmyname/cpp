#include <stdio.h>
#include <iostream>
#include <cstring>

#include "functions.h"
#include "otherFunctions.h"

// klasy u¿ywane w funkcjach:
#include "DateOfBirth.h"
#include "DateOfBirth.h"
#include "Base.h"
#include "Derived.h"
#include "Base2.h"
#include "Derived2.h"

void _011_const()
{
  #define MINUTE 60
  #define HOUR 3600
  #define DAY 86400

  printf("Minute=%d seconds\n", MINUTE);
  printf("Hour=%d seconds\n", HOUR);
  printf("Day=%d seconds\n", DAY);
}

void _012_const()
{
  //const double gravity; // uninitialized const 'gravity' [-fpermissive]
  const double gravity=9.81;
  //gravity=9.01; // assignment of read-only variable 'gravity'
  printf("Gravity is constant=%f\n", gravity);
}

void _013_const()
{
  const DateOfBirth DateOfBirth(1982, 6, 14);
  std::cout << "Day: " << DateOfBirth.getDay() <<std::endl;
  std::cout << "Month: " << DateOfBirth.getMonth() <<std::endl;
  std::cout << "Year: " << DateOfBirth.getYear() <<std::endl;

  DateOfBirth.printDateOfBirth();

//  DateOfBirth.changeDay(15); // Multiple markers at this line
                              // passing 'const DateOfBirth' as 'this' argument discards qualifiers [-fpermissive]
                              // Invalid arguments 'Candidates are: void changeDay(short int)'
}

void _015_static()
{
//  char *str1="abcdefg"; // warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
//  char *str1=(char *)"abcdefg"; // rzutowanie w C
  char *str1=const_cast<char*>("abcdefg");
  char *str2=const_cast<char*>("opqrstuvw");
  char *str3=const_cast<char*>("efghijklmnop");

  printf("%s\n", static_objects::modifyString1(str1, 0x64, 0x65, strlen(str1)));
  printf("%s\n", static_objects::modifyString1(str2, 0x70, 0x71, strlen(str2)));
  printf("%s\n", static_objects::modifyString1(str3, 0x70, 0x71, strlen(str3)));

  printf("%s\n", static_objects::modifyString2(str1, 0x64, 0x65, strlen(str1)));
  printf("%s\n", static_objects::modifyString2(str2, 0x70, 0x71, strlen(str2)));
  printf("%s\n", static_objects::modifyString2(str3, 0x70, 0x71, strlen(str3)));

//  printf("%s\n", static_objects::modifyString3(str1, 0x64, 0x65, strlen(str1)).c_str());
//  printf("%s\n", static_objects::modifyString3(str2, 0x70, 0x71, strlen(str2)).c_str());
//  printf("%s\n", static_objects::modifyString3(str3, 0x70, 0x71, strlen(str3)).c_str());

//  std::string string_1=str1;
//  std::string string_2=str2;
//  std::string string_3=str3;

//  static_objects::modifyString4(&string_1, 0x70, 0x71);
//  static_objects::modifyString4(&string_2, 0x70, 0x71);
//  static_objects::modifyString4(&string_3, 0x70, 0x71);
//  std::cout << string_1 << std::endl;
//  std::cout << string_2 << std::endl;
//  std::cout << string_3 << std::endl;
}

void _021_inline()
{

}
void _022_inline()
{

}
void _023_inline()
{

}

void _031_virtual()
{
  std::cout << "Size for Base class: " << sizeof(Base) << std::endl;
  std::cout << "Size for Derived class: " << sizeof(Derived) << std::endl;
  std::cout << "Size for Base2 class: " << sizeof(Base2) << std::endl;
  std::cout << "Size for Derived2 class: " << sizeof(Derived2) << std::endl;
}

void _032_virtual()
{
  clock_t start, finish;
  int sizeOfTable=1000;
  Base* tab[sizeOfTable];
  Base2* tab2[sizeOfTable];
  for(int i=0; i < sizeOfTable; i++)
  {
    tab[i]=new Derived();
    tab2[i]=new Derived2();
  }

  start=clock();
  for(int i=0; i < sizeOfTable; i++)
  {
    tab[i]->print();
  }
  finish=clock();
  std::cout << "Ró¿nica czasów z narzutem: " << finish-start << "ms" << std::endl;

  start=clock();
  for(int i=0; i < sizeOfTable; i++)
  {
    tab2[i]->print();
  }
  finish=clock();
  std::cout << "Ró¿nica czasów bez narzutu: " << finish-start << "ms" << std::endl;
}

void _035_virtual()
{
  Base* b;
  b=new Base();
  b->print();
  b=new Derived();
  b->print();
}

void _041_overloading()
{
  int i=2;
  double d=2.4;
  std::cout << "f(2)=" << function_overloading::f(i) << std::endl;
  std::cout << "f(2.4)=" << function_overloading::f(d) << std::endl;
}
