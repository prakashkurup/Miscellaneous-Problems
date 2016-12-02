/*
 * =====================================================================================
 *
 *       Filename:  balanced_paranthesis.c
 *
 *    Description:  Check for balanced paranthesis. 
 *
 *        Version:  1.0
 *        Created:  12/01/2016 07:35:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Prakash Kurup (), prakashkurup7@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Implementing stack to check for balance */
#define SIZE 101

char stack[SIZE];
int top = -1;

/* Function to push to stack for open brackets */
void push(char par)
{
	stack[++top] = par;	
}

/* Function to pop from stack for closed brackets */
void pop(void)
{
	top--;
}

/* Function to check for open and closed bracket pairs */
bool checkForPairs(char par)
{
	if (stack[top] == '{' && par == '}')
		return true;
	else if (stack[top] == '(' && par == ')')
		return true;
	else if (stack[top] == '[' && par == ']')
		return true;
	else
		return false;
}

/* Function to check for balanced paranthesis */
bool checkBalPar(const char *par)
{
	while (*par) {
		/* For open brackets */
		if (*par == '{' || *par == '(' || *par == '[') {
			/* Push to stack */
			push(*par);
		/* For closed brackets */
		} else if (*par == '}' || *par == ')' || *par == ']') {
			/* If pairs, pop from stack */
			if (checkForPairs(*par))
				pop();
			else
				return false;
		}
	
		par++;
	}
	
	/* If stack is empty, true */
	if (top == -1) {
		return true;
	} else {
		return false;
	}
}

int main(void)
{
	const char *par = "{{[(([]))]}}";
	
	checkBalPar(par) ? printf("Balanced\n") : printf("NOT balanced\n");

	return 0;
}
