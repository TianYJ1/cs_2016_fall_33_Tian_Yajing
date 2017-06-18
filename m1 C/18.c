#include<stdio.h>
#define MAX 20
int main()
{
 FILE *fa,*fb;
 char stra[MAX],strb[MAX],c;
 printf("Please enter the source file name:");
 gets(stra);
 printf("Please enter the target file name:");
 gets(strb);
 fa=fopen(stra,"r");
 fb=fopen(strb,"w");
 if(fa)
 {
  if(fb)
  {
   while((c=getc(fa))!=EOF)
    putc(c,fb);
   fclose(fa);
   fclose(fb);
  }
  else
   printf("can't open %s",strb);
 }
 else
  printf("can't open %s",stra);
}
