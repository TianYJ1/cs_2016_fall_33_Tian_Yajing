#include <stdlib.h> 
#include <stdio.h>

double asd(double *m, int n)
{    int i,d;
	double p;
	double o;
	p=m[1];
	for (i = 0; i< n; ++i)
	{
	  if (p<m[i]){
			p=m[i];
	  }
	}
	o=m[0];
 	for (i = 0; i< n; ++i)
	{
	  if (o>m[i]){
			o=m[i];
	  }
	} 
	d=p-o;
	return d;
}

int main()
{   double q;
	int n;
	int i=0;
	
	printf("how many:");
	scanf("%i", &n);
	double *m = (double*)malloc(n*10);
	printf("numbers: ");
	for (i = 0; i < n; ++i){
	scanf("%lf", &m[i]);
	}
	q=asd(m, n);
	printf("diversity=%lf\n", q);
	return 0;
}