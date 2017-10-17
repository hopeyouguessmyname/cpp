/*
 * Derived.cpp
 *
 *  Created on: 29.06.2017
 *      Author: 168625
 */
#include <stdio.h>
#include <iostream>

#include "otherFunctions.h"

#include "Derived.h"

Derived::Derived()
{
}

Derived::~Derived()
{
}

void Derived::print()
{
  std::cout << "Derived::print()" << std::endl;
}

void Derived::printToFile()
{
  writeLineToFile("tempFile.txt", "Derived::print()");
}
