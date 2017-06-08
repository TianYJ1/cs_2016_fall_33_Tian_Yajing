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
printf("§£§Ó§Ö§Õ§Ú§ä§Ö §á§å§ä§î §Ü §â§Ñ§ã§á§à§Ý§à§Ø§Ö§ß§Ú§ð §æ§Ñ§Û§Ý§Ñ §Ü§à§ä§à§â§í§Û §Ü§à§á§Ú§â§å§ð§ä(C:\/Games\/filename1.txt)");
gets(a);
printf("§£§Ó§Ö§Õ§Ú§ä§Ö §â§Ñ§ã§á§à§Ý§à§Ø§Ö§ß§Ú§Ö §æ§Ñ§Û§Ý§Ñ §Ü§å§Õ§Ñ §Ü§à§á§Ú§â§à§Ó§Ñ§ä§î (C:\/Games\/filename2.txt)");
gets(b);
copy(a,b);
printf("§³§Õ§Ö§Ý§Ñ§ß§à");
return 0;
}
