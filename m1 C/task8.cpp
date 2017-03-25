#include <stdio.h>
# include<math.h>
int main(void)
{
int a, b, c; 
printf("a b c,\n");
scanf("%d %d %d", &a, &b, &c); 
double delta = b*b - 4*a*c; 
double x1 = (-b + sqrt(delta))/(2 * a);
double x2 = (-b - sqrt(delta))/(2 * a);
if (delta>0) 
{
printf("2 answers\n");
printf(",x1 = %f\n",x1);
printf(",x2 = %f\n",x2);
}
else if (delta ==0) 
{
printf("1 answer\n");
printf("x1 = x2 =%f\n",x1);
}
else
{
printf("no\n");
}
return 0;
}
