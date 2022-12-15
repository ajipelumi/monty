#include "monty.h"

#include <stdlib.h>
#include <unistd.h>

/**
 * pint - print the number in the top of the stack
 * @stack: stack
 * @line_number: line number to use for printing error
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "%u: can't pint, stack empty\n", line_number);
		stackFree(stack);
		free(curLine);
		exit(EXIT_FAILURE);
	}

	tail = getTail(stack);
	printf("%i\n", tail->n);

	free(curLine);
	curLine = NULL;
}
