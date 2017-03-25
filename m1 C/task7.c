#include <stdio.h>
#include <math.h>

int add( int a, int b );
int sub( int a, int b );
int mul( int a, int b );
int div( int a, int b );



int main()

{
	int a;
	int b;
	char c;
	printf("please enter like 5+4\n");
	scanf("%d %c %d", &a,&c,&b);
	switch (c)
    {
                case '+':                               
                                 printf( "%d+%d=%d\n", a,b,add(a,b) );
                                 break;
                case '-':      
				                 printf( "%d-%d=%d\n", a,b,sub(a,b) );
                                 break;
                case '*': 
                                printf( "%d*%d=%d\n", a,b,mul(a,b) );
                                 break;
                case '/': 
                                  printf( "%d/%d=%d\n", a,b,div(a,b) );
                                 break;
                
                default:
                                printf( "operator error!\n" );
        }        
        return 0;
}



int add( int a, int b )
{
        return ( a + b );
}

int sub( int a, int b )
{
        return ( a - b );
} 

int mul( int a, int b )
{
        return ( a * b );
}

int div( int a, int b )
{
        return ( a / b );
} 

