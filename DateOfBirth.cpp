/*
 * DateOfBirth.cpp
 *
 *  Created on: 28.06.2017
 *      Author: 168625
 */

#include "DateOfBirth.h"

#include <stdio.h>

DateOfBirth::DateOfBirth(short iYear, short iMonth, short iDay) : year(iYear), month(iMonth), day(iDay)
{
}

void DateOfBirth::changeDay(short iDay)
{
  day=iDay;
}

void DateOfBirth::changeMonth(short iMonth)
{
  month=iMonth;
}

void DateOfBirth::changeYear(short iYear)
{
  year=iYear;
}

short DateOfBirth::getDay() const { return day; }
short DateOfBirth::getMonth() const { return month; }
short DateOfBirth::getYear() const { return year; }

void DateOfBirth::printDateOfBirth() const
{
  printf("%04d-%02d-%02d\n", year, month, day);
}
