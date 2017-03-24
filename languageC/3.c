#include <stdio.h>
int main()
{
	float R=0;
	float R1=0;
	float R2=0;

	printf("please put in R1:\n");
	scanf("%f",&R1);

	printf("please put in R2:\n");
	scanf("%f",&R2);

	R=1/(1/R1+1/R2);
	printf("The resistance of the two resistors in parallel is:%f\n",R);

	return 0;
}