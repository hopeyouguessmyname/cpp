#include <stdio.h>
#include <iostream>

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