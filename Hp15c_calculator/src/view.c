#include "view.h"

char n[10];

char* getInput(){
	printf("Write input, max 10  digits.\n");
	char c;
	int i=0;


	while( (c = getchar())!= 10 && i<10){
		n[i] = c; 
		i++;
	}
	n[i]=10;
	return n;
	
}
void updateView(){
	int index = 0;
	stack_node_t *my_stack = getStack();
	printf("\n-------------\n");
	while( index < my_stack->stack_index ){
		printf("stack:  %d\n", (my_stack->stack[index]));
		index++;
	}
		printf("-------------\n\n");
}
