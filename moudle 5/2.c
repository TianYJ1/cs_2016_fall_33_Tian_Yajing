#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float func(float x)
{
	return x*x*x;
}

int main()
{
    float h = 0.0, n=0.0, x = 0.0, p = 0.0, a=0.0, b=0.0, p1=0.0, p2=0.0, ans=0.0, i=0.0, k=1.0, ans1=0.0;

    printf("Enter the low limit:");
	scanf("%f", &a);
	printf("Enter the high limit:");
	scanf("%f", &b);
	printf("Enter the error :");
	scanf("%f", &n);
    i=(b-a)/(2*n);
    h=(b-a)/(2*n);
    p=(h/3)*(func(a)+func(b));
	while(b > a+2*k*i || b>a+(2*k+1)*i)
    {
        p1=(2*h/3)*(func(a+2*k*i));
        p2=(4*h/3)*(func(a+i*(2*k+1)));
        k=k+1.0;
        ans=ans+p1+p2;
	}
	ans1=p+ans;
	printf("Answer:%f\n", ans1);

    return 0;
}
