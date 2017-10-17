#include <stdlib.h>
#include <cstring>
#include <fstream>

#include "otherFunctions.h"

void writeLineToFile(std::string fileName, std::string line)
{
  std::fstream file(fileName.c_str(), std::ios::out | std::ios::app);
  if(file.good() == true)
  {
    file << line << std::endl;
    file.flush();
    file.close();
  }
}

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

namespace function_overloading
{
  int f(int i)
  {
    return i+5;
  }

  int f(double d)
  {
    return d+5;
  }
}
