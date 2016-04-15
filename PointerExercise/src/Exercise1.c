/*
 * Exercise1.c
 *
 *  Created on: 07/04/2016
 *      Author: jimmi
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x = 42; 						//adds 42 to x variable
	int *ip;							//declares pointer ip
	ip = &x;							//sets address of x to pointer
		printf("x: %d\n", x);			//prints 42 to console
		printf("*ip: %d\n", *ip);		//prints 42 x to console
		printf("ip: %d\n", ip);			//prints address of x
		printf("&ip: %d\n", &ip);		//prints address of pointer ip to console
		printf("&x: %d\n", &x);			//prints address of x to console
	x++;								//increments x to 43
	(*ip)++;							//increments x to 44
		printf("*ip: %d\n", *ip);		//prints 44 to console

	int y = 13;							//add 13 to y variable
	int *iq;							//declares pointer iq
	iq = &y;							//sets address of y to pointer
		printf("*iq:%d\n", *iq);		//prints 13 to console
	*iq = *ip;							//*ip = 44 (previous slide)
		printf("*iq:%d\n", *iq);		//prints 44 to console
	*ip = 5;							//adds 5 to x variable
	*iq = 10;							//adds 10 to y variable
		function_X(ip, iq);				//calls function_x with ip and iq
		printf("*ip:%d\n", *ip);		//prints  to console
		printf("*iq:%d\n", *iq);		//prints  to console
	int p = 22;							//adds 22 to p variable
	int q = 44;							//adds 44 to q variable
		function_X(&p, &q);				//calls function_x with p and q
		printf("p:%d\n", p);			//prints 44 to console
		printf("q:%d\n", q);			//prints 22 to console



}
void function_X(int *a, int *b)
		{
	int temp;							//initialize tempvariable
	temp = *a;							//set temp to a pointer
	*a = *b;							//sets a pointer to b pointer
	*b = temp;							//sets b pointer to temp variable
	}
