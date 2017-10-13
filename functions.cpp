#include <stdio.h>

void _011_const()
{
  #define MINUTE 60
  #define HOUR 3600
  #define DAY 86400

  printf("Minute=%d seconds\n", MINUTE);
  printf("Hour=%d seconds\n", HOUR);
  printf("Day=%d seconds\n", DAY);
}
