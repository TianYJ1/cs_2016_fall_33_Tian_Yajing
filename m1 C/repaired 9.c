#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN  1
#define OUT 0

int main()
{
    int c, i, j, nc, state;    //����nc���ڼ���һ�����ʳ���,state�����ж��Ƿ��ڼ���һ������
    int len;       //���ڱ�����ݱ������������Ҫ��ӡ�ĸ������
    int maxvalue;  //������󵥴�����
    int ovflow;    //���ڼ��㳬���涨���ȵĵ�����
    int wl[MAXWORD];

    state = OUT;
    nc = 0;
    ovflow = 0;   
    for (i = 0; i < MAXWORD; i++)   //wl����ͳ�Ƹ������ȵĵ�������
    {
        wl[i] = 0;    //���ȳ�ʼ�����飬ȫ��Ϊ0
    }
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
            if (nc > 0)       //˵��һ�����ʵĽ���
                if (nc < MAXWORD)
                    ++wl[nc];
                else    
                    ++ovflow;
            nc = 0;
        }
        else if (state == OUT)    //˵��һ�����ʵĿ�ʼ
        {
            state = IN;
            nc = 1;
        }
        else         //˵���ڼ���һ�����ʹ�����
            ++nc;
    }
    maxvalue = 0;
    for (i = 1; i < MAXWORD; i++)    //���ڼ������󵥴�����
    {
        if (wl[i] > maxvalue)
            maxvalue = wl[i];
    }
#if 0    //ˮƽֱ��ͼ
    for (i = 1; i < MAXWORD; ++i)
    {
        printf ("%5d - %5d : ", i, wl[i]);
        if (wl[i] > 0)
        {
            if ((len = wl[i] * MAXHIST / maxvalue) <= 0)
                len = 1;
        }
        else
        {
            len = 0;
        }
        while (len > 0)
        {
            printf("*");
            --len;
        }
        putchar ('\n');
    }
#else    //��ֱֱ��ͼ
    /* ��ֱֱ��ͼ��˼�����ڴ����ֵ��ʼ�������������£��������� */
    for (i = MAXHIST; i > 0; --i)
    {
        for (j = 1; j < MAXWORD; j++)
            if (wl[j] * MAXHIST / maxvalue > i) 
                printf(" * ");
            else
                printf("   ");
        putchar('\n');
    }

    for (i = 1; i < MAXWORD; i++)
        printf ("%4d ", i);
    putchar ('\n');
    for (i = 1; i < MAXWORD; i++)
        printf ("%4d ", wl[i]);
    putchar ('\n');
#endif
    if (ovflow > 0)
    {
        printf ("There are %d words >= %d\n", ovflow, MAXWORD);
    }

    return 0;
}
