#include <stdio.h>

void find_comment(int c);
void in_comment(void);
void in_short_comment(void);
FILE *in, *out;


int main()
{
int c;
char file_name[20];
char out_file_name[20];

printf("please input the name of file ");
gets(file_name);
in = fopen(file_name,"rb");
if((in = fopen(file_name, "rb")) == NULL)
{
perror(file_name);
return 1;
}
printf("please input the name of the new file ");
gets(out_file_name);
out = fopen(out_file_name, "wb");
while((c = fgetc(in)) != EOF)
{
find_comment(c);
}
fclose(in);
fclose(out);
return 0;
}void find_comment(int c)
{
int d;
if(c=='/')
if((d = fgetc(in)) =='*')
in_comment();
else if(d=='/')
in_short_comment();
else
{
fputc(c, out);
fputc(d, out);
}
else 
fputc(c, out);
}


void in_comment(void)
{
int c, d;
c=fgetc(in);
d=fgetc(in);
while(c != '*' || d != '/')
{
c=d;
d=fgetc(in);
}
}


void in_short_comment(void)
{
int c;
c=fgetc(in);
while(c != '\n')
c=fgetc(in);
fputc('\n', out);
}

