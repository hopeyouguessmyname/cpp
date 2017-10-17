#include <stdlib.h>
#include <cstring>

#include "otherFunctions.h"

namespace static_objects
{
  char* modifyString1(char *line, char from, char to, int sizeOfString)
  {
    char temp[sizeOfString];
    strncpy(temp, line, strlen(line));
    for(int i = 0; temp[i] != '\0'; i++)
      if(temp[i]==from)
        temp[i]=to;
    return line=temp;
  }

  char* modifyString2(char *line, char from, char to, int sizeOfString)
  {
    static char *temp = (char*)malloc(sizeof(*line)*sizeOfString);
    strncpy(temp, line, strlen(line));
    for(int i = 0; temp[i] != '\0'; i++)
      if(temp[i]==from)
        temp[i]=to;
    return line=temp;
  }

  std::string modifyString3(std::string& line, char from, char to)
  {
    for(std::string::iterator it = line.begin(); it != line.end(); it++)
      if(*it==from)
        *it=to;
    return line;
  }

  void modifyString4(std::string *line, char from, char to)
  {
//    for(std::string::iterator it = line->begin(); it != line->end(); it++)
//      if(*it==from)
//        *it=to;
  }
}
