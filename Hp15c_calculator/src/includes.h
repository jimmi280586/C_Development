#if !defined(INCLUDES)
#define INCLUDES

void error(int n);

typedef struct stack_node{
	int stack_index;
	int stack[4];
} stack_node_t;

#endif