#include<stdio.h>

#include<string.h>
main()

{int i,a[127]={0};

 char s[100];

 printf("Enter a string:\n");

 gets(s);

 for(i=0;i<strlen(s);i++)

   if(a[(int)s[i]]==0)

   {a[(int)s[i]]=1; printf("%c",s[i]);}

 printf("\n");

}