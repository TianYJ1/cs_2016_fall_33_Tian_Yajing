#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
void copy(char *c,char *x)
{ char str[1000];
FILE *C,*X;

C=fopen(c,"r");
X=fopen(x,"w");
char i;
while((i=fgetc(C))!=EOF)
{
fputc(i,X);
}
}

int main()
{setlocale(LC_CTYPE, "Russian");
char a[1000],b[1000];
printf("���ӧ֧էڧ�� ����� �� ��ѧ���ݧ�ا֧ߧڧ� ��ѧۧݧ� �ܧ������ �ܧ��ڧ����(C:\/Games\/filename1.txt)");
gets(a);
printf("���ӧ֧էڧ�� ��ѧ���ݧ�ا֧ߧڧ� ��ѧۧݧ� �ܧ�է� �ܧ��ڧ��ӧѧ�� (C:\/Games\/filename2.txt)");
gets(b);
copy(a,b);
printf("���է֧ݧѧߧ�");
return 0;
}
