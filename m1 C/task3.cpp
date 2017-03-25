#include <stdio.h>  
  
  
int main()  
{  
    float r1,r2,R;  
    printf("r1=\n");  
    scanf("%f",&r1);  
    printf("r2=\n");  
    scanf("%f",&r2);  
    R=1/(1/r1+1/r2);  
    printf("The parallel resistance R=%f",R);  
  
    return 0;  
}  
