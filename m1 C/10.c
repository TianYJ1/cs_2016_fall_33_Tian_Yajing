#include <stdio.h>
#include "viewbin.h"

unsigned rightrot(unsigned x, int n);
int countbits(unsigned x);

int main()
{
    unsigned int x;
    int n;
    
    printf("Enter the number:\nx: ");
    scanf("%d", &x);
    bin(x);//преобразуем в двоичный вид
    printf("n: ");
    scanf("%d", &n);
    printf("\n%d\n", rightrot(x, n));
    bin(rightrot(x, n));
    return 0;
}

