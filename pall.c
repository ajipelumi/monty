#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * pall - prints all the values on the stack, starting
 * from the top of the stack
 *
 * @stack: stack
 * @line_number: line number to use while printing error
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)line_number; /* unused parameter */
	node = getTail(stack); /* get the top node */
	while (node != NULL)
	{
		printf("%d\n", node->n); /* print element */
		node = node->prev; /* go to previous node */
	}
}

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
}
