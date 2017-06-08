#include <stdio.h>

#define IN 1
#define OUT 0

int main(){

	int c,state,length;

	c = state = length = 0;
	
	while((c = getchar()) != EOF){
		
		if(c == ' '||c == '\n'||c == '\t'){
			if(state == IN){
				putchar(':');
				for(int i = 0; i < length; i++){
					putchar('*');
				}
				putchar('\n');
			}
			state = OUT;
			length = 0;
		}
		else {
			state = IN;
			putchar(c);
			length++;
		}
		
	}
	
}
