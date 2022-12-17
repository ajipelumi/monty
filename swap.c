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
		exit(EXIT_FAILURE);
	}

	temp = tail->n;
	tail->n = tail->prev->n;
	tail->prev->n = temp;
}

/**
 * rotl - rotates the stack to the top
 *
 * @stack: stack
 * @line_number: line number to use while printing error
 *
 * Return: void
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int num;

	(void)line_number; /* unused parameter */
	if (*stack == NULL)
		return;

	/* store last element on stack */
	node = getTail(stack); /* get top element */

	/* move the top element to the bottom */
	while (node->prev)
	{
		num = node->n;
		node->n = node->prev->n;
		node->prev->n = num;
		node = node->prev;
	}

}

/**
 * rotr - rotates the stack to the bottom
 *
 * @stack: stack
 * @line_number: line number to use while printing error
 *
 * Return: void
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *node;
	int num;

	(void)line_number;
	if (*stack == NULL)
		return;

	node = *stack;

	/* move the last element to the top */
	while (node->next)
	{
		num = node->n;
		node->n = node->next->n;
		node->next->n = num;
		node = node->next;
	}
}
