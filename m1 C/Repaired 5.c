#include <stdio.h>
int main()
{
float H,S,A;
S=0;A=1;
int i;
printf("The H and The S\n");

for (i=0;i<=100;i++)
{
H=9*S/5+32;
printf("%-2f\t%5f\n",S,H);
S=S+A;
}
}
