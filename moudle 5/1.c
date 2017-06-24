#include <stdio.h>
#include <math.h>

float diff(float x) 
{
	float func;
	func = x*x; 
	return func;
}

int main()
{
	char sign;
	float a, b, c, x, k = 0, i = 0, m = 0;

	printf("Enter the error (the most is 9) :");
	scanf("%c", &sign);

	char str[] = "%.zf\n";
	str[2] = sign;

	printf("Enter the low limit: ");
	scanf("%f", &a);
	printf("Enter the high limit: ");
	scanf("%f", &b);
	printf("enter thr step: ");
	scanf("%f", &c);

	x = a;

	i = (1 / (2 * c))*((-3) * diff(x) + 4 * (diff(x + c)) - (diff(x + 2 * c)));
	m = (1 / (2 * c))*(-diff(x) + diff(x + 2 * c));
	printf(str, i);
	printf(str, m);

	while (x + 2 * c <= b) {
		k = (1 / (2 * c))*(diff(x) - 4 * (diff(x + c)) + 3 * (diff(x + 2 * c)));
		x = x + c;
		printf(str, k);
	}
	return 0;
}
