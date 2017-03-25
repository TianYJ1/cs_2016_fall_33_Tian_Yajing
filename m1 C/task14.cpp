#include<string.h>
#include<stdio.h>
main ()
{ char a[80],c;
  int i,b; 
  gets(a);
  b=strlen(a);
for(i=0;i<b/2;i++)
{ c=a[i];
a[i]=a[b-1-i];
a[b-1-i]=c;
}
printf("%s\n",a);
return 0;
}

