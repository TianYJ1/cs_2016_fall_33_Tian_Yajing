#include <stdio.h>
#define swap(t,x,y) {t temp; temp = a; a = b; b = temp;}
void main(void)
{
	int a, b;
	printf("input a,b\n");
	scanf("%d %d", &a, &b);
	swap(int, a, b);
	printf("%d %d\n", a, b);
	
}