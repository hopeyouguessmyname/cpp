/*
 * Base.cpp
 *
 *  Created on: 29.06.2017
 *      Author: 168625
 */
#include <stdio.h>
#include <iostream>

#include "otherFunctions.h"

#include "Base.h"

Base::Base()
{
}

Base::~Base()
{
}

void Base::print()
{
  std::cout << "Base::print()" << std::endl;
}

void Base::printToFile()
{
  writeLineToFile("tempFile.txt", "Base::print()");
}
