#include <stdio.h>
int main()
{
int n,i;
printf("enter a number:",n);
scanf("%d",&n);
for(i=n-1;i>0;i--)
{
n=n*i;
}
printf("%d",n);
return 0;   
}
