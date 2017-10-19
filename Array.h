/*
 * Array.h
 *
 *  Created on: 16.08.2017
 *      Author: 168625
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>
#include <cstddef> // size_t type

//template<typename T>
//class Array
//{
//    enum { N=10 };
//    T* data;
//    int count;
//    int capacity;
//
//  public:
//    Array();
//    ~Array();
//};

template<typename T>
class Array
{
    enum { INIT=10 };
    T* data;
    size_t count;
    size_t capacity;

  public:
    Array()
    {
      std::cout << "Array::Array()" << std::endl;
      count=0;
      data=new T[capacity=INIT];
    }

    ~Array()
    {
      std::cout << "Array::~Array()" << std::endl;
      delete []data;
    }

    void push_back(const T& element)
    {
      std::cout << "Array::push_back()" << std::endl;
      if(count == capacity)
      {
        T* newData = new T[capacity += INIT];
        for(size_t i=0; i<capacity; i++)
          newData[i]=data[i];
        delete []data;
        data=newData;
      }
      data[count++]=element;

    }

    void pop_back()
    {
      if(count>0)
        count--;
    }

    size_t size()
    {
      return count;
    }

    void display()
    {
      for(size_t i=0; i < count; i++)
      {
        std::cout << "The man no.: " << data+i << " Age: " << data[i].getAge() << std::endl;
      }
    }
};

#endif /* ARRAY_H_ */
