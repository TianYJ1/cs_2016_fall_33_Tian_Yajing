#include <stdio.h>
#include <math.h>

int main()
{
    float answer;
    float a;
    float b;
    char c;

    printf("please enter like 5+4\n");
    scanf("%f%c%f", &a, &c, &b);

    switch(c)
    {
    case '+':
        answer=a+b;
        printf("answer:%.4f", answer);
        break;

    case '-':
        answer=a-b;
        printf("answer:%.4f", answer);
        break;

    case '*':
        answer=a*b;
        printf("answer:%.4f", answer);
        break;

    case '/':
        answer=a / b;
        printf("answer:%.4f", answer);
        break;

    case '^':
        answer=pow(a,b);
        printf("answer:%.4f", answer);
        break;

    case '%':
        answer=a/100*b;
        printf("answer:%.4f", answer);
        break;

    default:
        printf("Error");




    }
    return 0;
}
