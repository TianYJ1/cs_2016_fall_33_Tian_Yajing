#include <stdio.h>

int rightrot(int x, int n)
{
	int i, j;
	i = x >> n;
	j = x << (sizeof(x) * 8 - n);

	return i | j;
}
int main()
{
	int x, n;
	printf("Enter the number x:");
	scanf("%i", &x);
	printf("Enter the number n:");
	scanf("%i", &n);
	printf("%i\n", rightrot(x, n));
	return 0;
}
