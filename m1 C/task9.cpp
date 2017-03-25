#include<stdio.h>
int fun(int n) 
{
  if(n<=1)
    return n;
  else
    return fun(n-1) + fun(n-2);
}

int main()
{
    int n; 
    printf("n");
    scanf("%d",&n);
    //int *a = (int*)malloc((n+1)*sizeof(int));
    int i; 
    for (i = 0; i < n+1; i++) 
   { 
       printf("%d, ", fun(i)); 
      if (i != 0 && i%5 == 0)  
       printf("\n");
    }  
    printf(" %d £º%d\n", n, fun(n));
    return 0; 
} 
