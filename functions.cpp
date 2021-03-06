#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>

#include "functions.h"
#include "otherFunctions.h"

// klasy u�ywane w funkcjach:
#include "DateOfBirth.h"
#include "DateOfBirth.h"
#include "Base.h"
#include "Derived.h"
#include "Base2.h"
#include "Derived2.h"
#include "Point.h"
#include "Man.h"
#include "Two.h"

#include "Array.h"

void _011_const()
{
  #define MINUTE 60
  #define HOUR 3600
  #define DAY 86400

  printf("Minute=%d seconds\n", MINUTE);
  printf("Hour=%d seconds\n", HOUR);
  printf("Day=%d seconds\n", DAY);
}

void _012_const()
{
  //const double gravity; // uninitialized const 'gravity' [-fpermissive]
  const double gravity=9.81;
  //gravity=9.01; // assignment of read-only variable 'gravity'
  printf("Gravity is constant=%f\n", gravity);
}

void _013_const()
{
  const DateOfBirth DateOfBirth(1982, 6, 14);
  std::cout << "Day: " << DateOfBirth.getDay() <<std::endl;
  std::cout << "Month: " << DateOfBirth.getMonth() <<std::endl;
  std::cout << "Year: " << DateOfBirth.getYear() <<std::endl;

  DateOfBirth.printDateOfBirth();

//  DateOfBirth.changeDay(15); // Multiple markers at this line
                              // passing 'const DateOfBirth' as 'this' argument discards qualifiers [-fpermissive]
                              // Invalid arguments 'Candidates are: void changeDay(short int)'
}

void _014_preprocessor()
{
  #define SEPARATOR '@'

  char line[16];
//  char *line = (char*)malloc(sizeof(char)*16);
  strncpy(line, "_______|_______", 15);
  printf("%s\n", line);


  // 1. spos�b:
  char separator[2] = { SEPARATOR };
  char newline1[16];
//  char *newline = (char*)malloc(sizeof(char)*16);
  strcpy(newline1, "_______");
  strcat(newline1, separator);
  strcat(newline1, "_______");
  printf("%s\n", newline1);

  // 2. sposob:
  char newline2[16];
//  char newline2 = (char*)malloc(sizeof(char)*16);
  sprintf(newline2, "_______%c_______", SEPARATOR);
  printf("%s\n", newline2);
}

void _015_static()
{
//  char *str1="abcdefg"; // warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
//  char *str1=(char *)"abcdefg"; // rzutowanie w C
  char *str1=const_cast<char*>("abcdefg");
  char *str2=const_cast<char*>("opqrstuvw");
  char *str3=const_cast<char*>("efghijklmnop");

  printf("%s\n", static_objects::modifyString1(str1, 0x64, 0x65, strlen(str1)));
  printf("%s\n", static_objects::modifyString1(str2, 0x70, 0x71, strlen(str2)));
  printf("%s\n", static_objects::modifyString1(str3, 0x70, 0x71, strlen(str3)));

  printf("%s\n", static_objects::modifyString2(str1, 0x64, 0x65, strlen(str1)));
  printf("%s\n", static_objects::modifyString2(str2, 0x70, 0x71, strlen(str2)));
  printf("%s\n", static_objects::modifyString2(str3, 0x70, 0x71, strlen(str3)));

//  printf("%s\n", static_objects::modifyString3(str1, 0x64, 0x65, strlen(str1)).c_str());
//  printf("%s\n", static_objects::modifyString3(str2, 0x70, 0x71, strlen(str2)).c_str());
//  printf("%s\n", static_objects::modifyString3(str3, 0x70, 0x71, strlen(str3)).c_str());

//  std::string string_1=str1;
//  std::string string_2=str2;
//  std::string string_3=str3;

//  static_objects::modifyString4(&string_1, 0x70, 0x71);
//  static_objects::modifyString4(&string_2, 0x70, 0x71);
//  static_objects::modifyString4(&string_3, 0x70, 0x71);
//  std::cout << string_1 << std::endl;
//  std::cout << string_2 << std::endl;
//  std::cout << string_3 << std::endl;
}

void _021_inline()
{

}
void _022_inline()
{

}
void _023_inline()
{

}

void _029_kompozycja()
{
  Two *t = new Two();
  t->printOne();
}

void _031_virtual()
{
  std::cout << "Size for Base class: " << sizeof(Base) << std::endl;
  std::cout << "Size for Derived class: " << sizeof(Derived) << std::endl;
  std::cout << "Size for Base2 class: " << sizeof(Base2) << std::endl;
  std::cout << "Size for Derived2 class: " << sizeof(Derived2) << std::endl;
}

void _032_virtual()
{
  clock_t start, finish;
  int sizeOfTable=1000;
  Base* tab[sizeOfTable];
  Base2* tab2[sizeOfTable];
  for(int i=0; i < sizeOfTable; i++)
  {
    tab[i]=new Derived();
    tab2[i]=new Derived2();
  }

  start=clock();
  for(int i=0; i < sizeOfTable; i++)
  {
    tab[i]->print();
  }
  finish=clock();
  std::cout << "R�nica czas�w z narzutem: " << finish-start << "ms" << std::endl;

  start=clock();
  for(int i=0; i < sizeOfTable; i++)
  {
    tab2[i]->print();
  }
  finish=clock();
  std::cout << "R�nica czas�w bez narzutu: " << finish-start << "ms" << std::endl;
}

void _035_virtual()
{
  Base* b;
  b=new Base();
  b->print();
  b=new Derived();
  b->print();
}

void _041_overloading()
{
  int i=2;
  double d=2.4;
  std::cout << "f(2)=" << function_overloading::f(i) << std::endl;
  std::cout << "f(2.4)=" << function_overloading::f(d) << std::endl;
}

void _071_union()
{
  union Unn
  {
      //static double d; // Union::d may not be static because it is a member of a union
      int n;              // occupies 4 bytes
      unsigned int s[2];  // occupies 8 bytes
      char c;             // occupies 1 byte
  };                      // the whole union occupies 8 bytes

  std::cout << "sizeof(int)=" << sizeof(int) << std::endl;
  std::cout << "sizeof(unsigned int[2])=" << sizeof(unsigned int[2]) << std::endl;
  std::cout << "sizeof(char)=" << sizeof(char) << std::endl;

  std::cout << "sizeof(Unn)=" << sizeof(Unn) << std::endl;

  Unn u;
  u.s[0]=0;
  u.s[1]=0;
  std::cout << "s[0]=" << std::hex << u.s[0] << std::endl;
  std::cout << "s[1]=" << std::hex << u.s[1] << std::endl;
  u.c=255;
  std::cout << "Zmienna zapisana na jednym bajcie nadpisuje najm�odszy bajt pozosta�ych zmiennych." << std::endl;
  std::cout << "s[0]=" << std::hex << u.s[0] << std::endl;
  std::cout << "s[1]=" << std::hex << u.s[1] << std::endl;
}

void _081_pointerVSreferency()
{
  int i=23;

  std::cout << "Referencja musi by� zainicjalizowana w momencie deklaracji." << std::endl;
  int &r = i;
  std::cout << "Wska�nik nie musi." << std::endl;
  int *j = &i;
  std::cout << "Sta�y wska�nik te� nie musi." << std::endl;
  int const *k = &i;

  std::cout << "this line is only to get variables used: "<< r << *j << *k << std::endl;
}

void _082_pointerVSreferency()
{
  int i=1, j=2;

  int &r = i;
  std::cout << "Referencji nie mo�na przestawi� na inn� zmienn�. Wska�nikowi mo�na przypisa� adres innej zmiennej" << std::endl;
  r = j; // przypisanie referencji warto�ci zmiennej j
  std::cout << "r=" << r << std::endl;
  std::cout << "i=" << i << std::endl;
  i=7;
  std::cout << "i=" << i << std::endl;
  //referencja dalej wskazuje na zmienn� i

  std::cout << "O ile nie jest sta�ym wska�nikiem." << std::endl;
//  int* const k; //uninitialized const 'k'
  int* const k=&i;
  std::cout << "*k=" << *k << std::endl;
//  k=&j; //assignment of read-only variable 'k'
//  std::cout << "*k=" << *k << std::endl;
}

void _091_const_cast()
{
  const int i=9;
  const int& j=i;
//  const_cast_namespace::printInteger(&i); // invalid conversion from 'const int*' to 'int*' [-fpermissive]
  const_cast_namespace::printInteger(const_cast<int*> (&i));
//  const_cast_namespace::printInteger(j); // binding 'const int' to reference of type 'int&' discards qualifiers
  const_cast_namespace::printInteger(const_cast<int&> (j));
}

void _092_const_cast()
{
  double pi=3.14; // pi+=0.01; // mo�na zmienic
  const double* zmienna=&pi; // *zmienna+=0.01; // nie mo�na zmienic
  double* d=const_cast<double*>(zmienna); // *d+=0.01; // mo�na zmienic
  std::cout << *d << std::endl;
}

void _101_static_cast()
{
  float f=4.567856; // pojedyncza precyzja - dok�adno�c 6-7 cyfr po przecinku
  std::cout << bitset_namespace::floatToBitset(f) << std::endl;

  double d=4.567856; // podw�jna precyzja - dok�adnosc 15-16 cyfr po przecinku
  std::cout << bitset_namespace::doubleToBitset(d) << std::endl;

  double d2=static_cast<double>(f);
  std::cout << bitset_namespace::doubleToBitset(d2) << std::endl;

//  rzutowanie static_cast<double>(float) przycina precyzj� liczby typu double do typu float
//  przyci�cie precyzji polega na wyzerowaniu tych bit�w z mantysy liczby typu double,
//  kt�re wychodz� poza rozmiar mantysy liczby typu float
}

void _102_static_cast()
{
  float f=4.567856;
  std::cout << bitset_namespace::floatToBitset(f) << std::endl;

  double d=4.567856;
  std::cout << bitset_namespace::doubleToBitset(d) << std::endl;

  float f2=static_cast<float>(d);
  std::cout << bitset_namespace::floatToBitset(f2) << std::endl;

//  rzutowanie static_cast<float>(double) przycina precyzj� liczby typu double do typu float
//  przyci�cie precyzji polega na wybraniu pierwszych 23 bit�w z mantysy liczby typu double
//  i wstawieniu ich do mantysy liczby typu float.
}

void _103_static_cast()
{
  float f=4.567856;
  std::cout << bitset_namespace::floatToBitset(f) << std::endl;

  short s=static_cast<short>(f);
  std::cout << bitset_namespace::shortToBitset(s) << std::endl;

  int i=static_cast<int>(f);
  std::cout << bitset_namespace::intToBitset(i) << std::endl;

  long l=static_cast<long>(f);
  std::cout << bitset_namespace::longToBitset(l) << std::endl;

  long long ll=static_cast<long long>(f);
  std::cout << bitset_namespace::longlongToBitset(ll) << std::endl;
}

void _104_static_cast()
{
  short s=4;
  std::cout << bitset_namespace::shortToBitset(s) << std::endl;

  float f=static_cast<float>(s);
  std::cout << bitset_namespace::floatToBitset(f) << std::endl;

  int i=4;
  std::cout << bitset_namespace::intToBitset(i) << std::endl;

  f=static_cast<float>(i);
  std::cout << bitset_namespace::floatToBitset(f) << std::endl;

  long l=4;
  std::cout << bitset_namespace::longToBitset(l) << std::endl;

  f=static_cast<float>(l);
  std::cout << bitset_namespace::floatToBitset(f) << std::endl;

  long long ll=4;
  std::cout << bitset_namespace::longlongToBitset(ll) << std::endl;

  f=static_cast<float>(ll);
  std::cout << bitset_namespace::floatToBitset(f) << std::endl;
}

void _201_auto()
{
  std::vector<int> v={1,23, 34, 45, 56, 67, 78, 89, 90};
//  - could not convert '{1, 23, 34, 45, 56, 67, 78, 89, 90}' from '<brace-enclosed initializer list>' to 'std::vector<int>'
//  - in C++98 'v' must be initialized by constructor, not by '{...}'
//  C/C++ Build -> Settings -> Tool Settings -> Cygwin C++ Compiler -> Miscellaneous -> Other Flags.
//  Put -std=c++0x (or for newer compiler version -std=c++11 at the end).
  for(auto it=v.begin(); it!=v.end(); it++)
  {
    std::cout << *it << ", ";
  } std::cout << std::endl;
//  Zastosowanie: Ograniczenie rozwlek�o�ci kodu
//  Ten sam efekt mo�na uzyskac za pomoc� typedef
  typedef std::vector<int>::iterator iter;
  for(iter it=v.begin(); it!=v.end(); it++)
  {
    std::cout << *it << ", ";
  } std::cout << std::endl;
}

void _202_auto()
{
  Point<int> P1(11, 22, 33);
  Point<double> P2(1.23, 2.34, 3.45);

  auto A = P1;
  auto B = P2;
//  docelowo przypisywana wartosc ma byc zwracana z funkcji.
//  funkcja ta powinna zwracac typ szablonowy.
}

void _211_nullptr()
{
//  Cplusplus_11::f(NULL); // call of `f(NULL)` is ambiguous
  Cplusplus_11::f(nullptr);
}

void _212_nullptr()
{
  std::vector<Point<int>*> vec = {new Point<int>(1,2,3), nullptr, new Point<int>(3,4,5)};
  for(auto it=vec.begin(); it < vec.end(); it++)
  {
    if((*it)!=nullptr)
      (*it)->print();
  }
}

void _221_constexpr()
{
  int tab[Cplusplus_11::getFive()];
  for(int i=0; i < Cplusplus_11::getFive(); i++)
  {
    std::cout << tab[i] << ", "; // �mieci
  } std::cout << std::endl;

//  int tab2[5];
//  for(int i=0; i < 5; i++)
//    {
//      std::cout << tab2[i] << ", "; // �mieci
//    } std::cout << std::endl;
}

void _301_Array()
{
  Array<Man> myArray;

  int n=12;
  for(int i=1; i <= n; i++)
  {
    Man* m = new Man(i);
    myArray.push_back(*m);
//    delete m; // czy jest potrzebne? - sprawdzic czy nie powoduje wyciek�w pami�ci

    std::cout << myArray.size() << std::endl;
  }
  myArray.display();
  myArray.pop_back();
  myArray.pop_back();
  myArray.display();
}
