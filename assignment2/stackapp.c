/* CS261- Assignment 2 - Part 3 */
/* Name: Joseph DePrey
 * Date: 4/17/2016
 * Solution description: Using a stack to check for balanced parentheses, braces, and brackets
 *	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post: return 1 if balanced, 0 if unbalanced
*/
int isBalanced(char* s)
{
	/* check s is not null.  using if function because assert not included */
	if(s == NULL)
		return 0;

	char testChar;
	/* create stack to hold parentheses, braces, and brackets */
	DynArr *testStack;
	testStack = newDynArr(1);

	/* iterate through string until null char is reached */
	do
	{
		testChar = nextChar(s);
		/* if (, {, or [ are found add them to stack */
		if(EQ(testChar, '(') ||
		   EQ(testChar, '{') ||
		   EQ(testChar, '['))
		{
			pushDynArr(testStack, testChar);
		}
		/* if ), }, or ] are found then first check if balanced */
		else if(EQ(testChar, ')') ||
		   		EQ(testChar, '}') ||
		   		EQ(testChar, ']'))
		{	
			/* if the stack is empty or top element does not pair 
			   with the symbol then it is not balanced */
			if(EQ(sizeDynArr(testStack), 0) ||
				(EQ(testChar, ')') && !EQ(topDynArr(testStack),'('))||
		   		(EQ(testChar, '}') && !EQ(topDynArr(testStack),'{'))||
		   		(EQ(testChar, ']') && !EQ(topDynArr(testStack),'[')))
			{
				 return 0;
			}
			else{
				popDynArr(testStack);
			}
		}

	}
	while(!EQ(testChar, '\0'));
	
	/* string is balanced */
	return 1;

}


int main(int argc, char* argv[]){
	
	char* s=argv[1];	
	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

