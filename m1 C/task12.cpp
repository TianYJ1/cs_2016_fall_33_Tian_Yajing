#include <stdio.h>
#include <string.h>
 
#define MAX 80
 
int main()
{
    char arr[MAX + 1];
    char max;
    int len;
    int i;
 
    printf("Input a string:\n");
    gets(arr);
 
    max = '\0';
    len = strlen(arr);
    for(i=0; i<len; i++)
    {
        if(arr[i] > max)
       {
            max = arr[i];
        }
    }
 
    printf("The largest character is \'%c\'.The?ASCII is %d.\n", max, max);
}
