#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * pall -  prints all the values on the stack, starting from the top of the stack
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
	while (node->prev != NULL)
	{
		printf("%d\n", node->n); /* print element */
		node = node->prev; /* reverse node */
	}
}
