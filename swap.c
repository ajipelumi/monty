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
	stack_t *tail, *temp, *node;
	int count;

	tail = getTail(stack); /* get the last node */
	count = stackCount(stack);
	if (count < 2) /* stack contains less than 2 elements */
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		stackFree(stack);
		free(curLine);
		exit(EXIT_FAILURE);
	}

	if (count == 2) /* only 2 elements on the stack */
	{
		temp = tail->prev;
		temp->prev = tail;
		tail->next = temp;
		temp->next = NULL;
		tail->prev = NULL;
	}

	else /* more than 2 elements on the stack */
	{
		temp = tail->prev;
		node = temp->prev;
		node->next = tail;
		tail->prev = node;
		tail->next = temp;
		temp->prev = tail;
		temp->next = NULL;
	}

	free(curLine);
	curLine = NULL;
}
