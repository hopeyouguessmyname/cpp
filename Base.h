/*
 * Base.h
 *
 *  Created on: 29.06.2017
 *      Author: 168625
 */

#ifndef BASE_H_
#define BASE_H_

class Base
{
  public:
    Base();
    virtual ~Base();

    virtual void print();
    void printToFile();
};

#endif /* BASE_H_ */
