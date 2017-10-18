/*
 * Point.h
 *
 *  Created on: 14.08.2017
 *      Author: 168625
 */

#ifndef POINT_H_
#define POINT_H_

#include <iostream>


template<typename T>
class Point
{
    T x, y, z;

  public:
    Point(T argX, T argY, T argZ) : x(argX), y(argY), z(argZ){}
    ~Point(){}
    void print(){ std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl; }
};


#endif /* POINT_H_ */
