#include "monty.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: stack
 * @line_number: line number to use while printing error
 *
 * Return: void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;
	int count, temp;

	tail = getTail(stack); /* get the last node */
	count = stackCount(stack);
	if (count < 2) /* stack contains less than 2 elements */
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		stackFree(stack);
		free(curLine);
		exit(EXIT_FAILURE);
	}

	temp = tail->n;
	tail->n = tail->prev->n;
	tail->prev->n = temp;

	/* free(curLine);
	curLine = NULL; */
}
