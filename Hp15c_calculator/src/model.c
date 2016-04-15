#include "model.h"

stack_node_t *my_stack;

void init(){
	my_stack = malloc(sizeof(stack_node_t));
	my_stack->stack_index = 0;
}


int pop(){
	if( my_stack->stack_index > 0 ){
		my_stack->stack_index--;
		return my_stack->stack[my_stack->stack_index];
	}
	else{
		error(1);
		return 1;
	}
	
	
	
}
void push(int n){
	if( my_stack->stack_index < 4 ){
		my_stack->stack[my_stack->stack_index]=n;
		my_stack->stack_index ++;
	}
	else{
		error(2);
	}
}

stack_node_t* getStack(){
	
	return my_stack;
}