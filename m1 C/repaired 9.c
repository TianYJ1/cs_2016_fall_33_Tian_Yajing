#include <stdio.h>

#define MAXHIST 15
#define MAXWORD 11
#define IN  1
#define OUT 0

int main()
{
    int c, i, j, nc, state;    //其中nc用于计算一个单词长度,state用于判断是否在计算一个单词
    int len;       //用于保存根据比例计算出来需要打印的个数结果
    int maxvalue;  //保存最大单词数量
    int ovflow;    //用于计算超过规定长度的单词数
    int wl[MAXWORD];

    state = OUT;
    nc = 0;
    ovflow = 0;   
    for (i = 0; i < MAXWORD; i++)   //wl用于统计各个长度的单词数量
    {
        wl[i] = 0;    //首先初始化数组，全设为0
    }
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
            if (nc > 0)       //说明一个单词的结束
                if (nc < MAXWORD)
                    ++wl[nc];
                else    
                    ++ovflow;
            nc = 0;
        }
        else if (state == OUT)    //说明一个单词的开始
        {
            state = IN;
            nc = 1;
        }
        else         //说明在计算一个单词过程中
            ++nc;
    }
    maxvalue = 0;
    for (i = 1; i < MAXWORD; i++)    //用于计算出最大单词数量
    {
        if (wl[i] > maxvalue)
            maxvalue = wl[i];
    }
#if 0    //水平直方图
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
#else    //垂直直方图
    /* 垂直直方图的思想在于从最大值开始遍历，由上往下，由左往右 */
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
