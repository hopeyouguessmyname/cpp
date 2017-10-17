#include <stdio.h>
#include <iostream>
#include <cstring>

#include "functions.h"
#include "otherFunctions.h"

// klasy używane w funkcjach:
#include "DateOfBirth.h"

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
  char *str1="abcdefg";
  char *str2="opqrstuvw";
  char *str3="efghijklmnop";

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
