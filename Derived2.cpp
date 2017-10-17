/*
 * Derived2.cpp
 *
 *  Created on: 29.06.2017
 *      Author: 168625
 */
#include <stdio.h>

#include "otherFunctions.h"

#include "Derived2.h"

Derived2::Derived2()
{
}

Derived2::~Derived2()
{
}

void Derived2::print()
{
  writeLineToFile("tempFile.txt", "Derived2::print()");
}
