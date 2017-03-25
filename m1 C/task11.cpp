#include<stdio.h>
int main()
{
int num = 0, a, j=1;
scanf("%d", &a);

while(a)
{
num += (a%10) * j;
a /= 10;
j *= 2;
}
printf("%d\n", num);
return 0;

}
