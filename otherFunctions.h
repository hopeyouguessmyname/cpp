#include <string>

namespace static_objects
{
  char* modifyString1(char *line, char from, char to, int sizeOfString);
  char* modifyString2(char *line, char from, char to, int sizeOfString);
  std::string modifyString3(std::string line, char from, char to, int sizeOfString);
  void modifyString4(std::string *line, char from, char to);
}
