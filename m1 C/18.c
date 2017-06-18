#include <stdio.h>
int Copy_File(char* in_path,char* out_path)
{
	FILE* in=NULL;
	FILE* out=NULL;
if((in=fopen(in_path,"rb"))==NULL)
	{
		printf("Невозможно открыть исходный файл!\n");
		return(1);
	}
	if((out=fopen(out_path,"wb+"))==NULL)
	{
		printf("Невозможно создать целевой файл!\n");
		fclose(in);
		return(1);
	}
	char data;
	while(!feof(in))
	{
		if(1==fread(&data,sizeof(char),1,in))
			fwrite(&data,sizeof(char),1,out);
	}
	fclose(in);
	fclose(out);
		
	return(0);
}
int main()
{
	char in_path[256];
	char out_path[256];
printf("Введите путь к исходному файлу: ");
	scanf("%s",in_path);
	printf("Введите путь к файлу назначения: ");
	scanf("%s",out_path);
	if(Copy_File(in_path,out_path))
	{
		printf("Копирование не удалось!");
	}else
		printf("успех копирования!");
	return(0);
}
