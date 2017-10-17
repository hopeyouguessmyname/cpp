#include <string>

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
