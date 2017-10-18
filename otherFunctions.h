#include <string>
#include <bitset>

void writeLineToFile(std::string fileName, std::string line);

namespace static_objects
{
  char* modifyString1(char *line, char from, char to, int sizeOfString);
  char* modifyString2(char *line, char from, char to, int sizeOfString);
  std::string modifyString3(std::string line, char from, char to, int sizeOfString);
  void modifyString4(std::string *line, char from, char to);
}

namespace function_overloading
{
  // funcje na u¿ytek przedstawienia przeci¹¿enia funkcji
  int f(int);
  int f(double);
  //double f(double); // ambiguating new declaration of 'double f(double)'
}

namespace const_cast_namespace
{
  // funkcje na u¿ytek przedstawienia rzutowania const_cast
  void printInteger(int*);
  void printInteger(int&);
}

namespace bitset_namespace
{
  std::bitset<32ul> floatToBitset(float);
  std::bitset<64ul> doubleToBitset(double);
  std::bitset<16ul> shortToBitset(short);
  std::bitset<32ul> intToBitset(int);
  std::bitset<32ul> longToBitset(long);
  std::bitset<64ul> longlongToBitset(long long);
}
