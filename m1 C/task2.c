 
#include<stdio.h>

int main()
{
    int day=19;
    int month=1;
    int t;
    printf("day=%d\n",day);
    printf("month=%d\n",month);
    t=month;
    month=day;
    day=t;
    printf("day=%d\n",day);
    printf("month=%d\n",month);
    return 0;
}
