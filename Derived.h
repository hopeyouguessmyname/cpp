/*
 * Derived.h
 *
 *  Created on: 29.06.2017
 *      Author: 168625
 */

#ifndef DERIVED_H_
#define DERIVED_H_

#include "Base.h"

class Derived: public Base
{
  public:
    Derived();
    /*virtual*/ ~Derived();

    void print();
    void printToFile(); // 035
};

#endif /* DERIVED_H_ */
