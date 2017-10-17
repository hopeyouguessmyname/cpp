/*
 * Base2.cpp
 *
 *  Created on: 29.06.2017
 *      Author: 168625
 */
#include <stdio.h>

#include "otherFunctions.h"

#include "Base2.h"

Base2::Base2()
{
}

Base2::~Base2()
{
}

void Base2::print()
{
  writeLineToFile("tempFile.txt", "Base2::print()");
}
