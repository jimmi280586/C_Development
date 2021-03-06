#include "includes.h"
#include "view.h"
#include "model.h"

int main(void){

	init();

	while(1){
		char *c = getInput();
		int n, i=0;
		if(*c == '-'){
			printf("- pressed\n");
			int a = pop();
			int b = pop();
			push(b-a);
		}
		else if(*c == '+'){
			printf("+ pressed\n");
			int a = pop();
			int b = pop();
			push(b+a);
		}
		else if(*c == '*'){
			printf("* pressed\n");
			// your code ...
		}
		else if(*c == 's'){ // 's' means swap the two top elements on the stack 
			printf("s pressed\n");
			// your code to swap the two top elements
		}
		else{
			n=atoi(c);
			printf("The number %d\n", n);
			push(n);
		}
	
		updateView();
	}
}



void error(int n){
	switch(n){
		case 1:
			printf("Stack empty\n");
			break;
		case 2:
			printf("Stack overflow\n");
	}
	
}
