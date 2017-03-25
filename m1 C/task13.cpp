# include <stdio.h>
# define MAX 20
# define OUT 0
# define IN 1

int main(void)
{
	int length[MAX];
	int c;
	int vocl;
	int state = OUT;
	int i;
	
	for(vocl = 0; vocl < MAX; vocl++){
		length[vocl] = 0;
	}
	while((c = getchar()) != EOF){
		if(c != ' ' && c != '\t' && c != '\n'){
			if(state == OUT){
				vocl = 1;
			} else{
				vocl++;
			}
			state = IN;
		} else{
			length[vocl]++;
			vocl = 0;
		}
	}
	for(vocl = 0; vocl < MAX; vocl++){
		if(length[vocl] != 0){
			printf("%2d  ", vocl);
			for(i = 1; i <= length[vocl]; i++){
				putchar('*');
			}
			putchar('\n');
		}
	}
}

