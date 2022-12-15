#include <stdlib.h>

#include "monty.h"

/**
 * push - push a number on the stack
 * @stack: stack
 * @line_number: line number to use while printing error
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack = stack;/*temporarily supressing unused arguments error*/
	printf("line number = %u\nline = %s\n", line_number, curLine);
	free(curLine);
	curLine = NULL;
}
