#include<stdio.h>
int main()
{
int Fibonacci(int n);
int n,i,c=0;
 
printf("please enter n:");
scanf("%d",&n);
for(i=1; i<=n; i++)
{
c = Fibonacci(i);
printf("%12ld",c);
if(i%4==0) 
printf("\n");
}
}
 
int Fibonacci(int n)
{
long int f;
 
if(n==1 || n==2)
{
f=1;
}
else
if(n>=3)
f = Fibonacci(n-1) + Fibonacci(n-2);
return f;
}
