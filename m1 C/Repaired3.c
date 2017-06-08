#include <stdio.h>

int main() 
{
	float x, y, a, b, c, d;
	printf("Enter the resistances,likes a+bi,x+yi\n ");
	scanf("%f+%fi,%f+%fi", &x, &y, &a, &b);
	c = (x*x*a + x*a*a + x*b*b + a*y*y) / (x*x+a*a+2*a*x+y*y+b*b+2*y*b);
	d = (x*x*b + a*a*y + y*y*b + y*b*b) / (x*x+a*a+2*a*x+y*y+b*b+2*y*b);
	printf("%.5f+%.5fi\n", c, d);
	return 0;
}
