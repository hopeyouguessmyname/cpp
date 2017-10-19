/*
 * Man.cpp
 *
 *  Created on: 16.08.2017
 *      Author: 168625
 */

#include <iostream>

#include "Man.h"

Man::Man()
{
  std::cout << "Man::Man()" << std::endl;

}

Man::Man(int p_age) : age(p_age)
{
  std::cout << "Man::Man(int)" << std::endl;
}

Man::~Man()
{
  std::cout << "Man::~Man()" << std::endl;
}

int Man::getAge()
{
  return age;
}
