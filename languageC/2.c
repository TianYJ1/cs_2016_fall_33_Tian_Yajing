#include <stdio.h>

int main()
{
 int day = 19;
 int month = 1;
 printf("%d %d\n", day, month);
 int c = day;
   day =month ;
   month = c;
 printf("%d %d\n", day, month);

    return 0;
}

