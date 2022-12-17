#include "monty.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * pchar - prints the char at the top of the stack
 *
 * @stack: stack
 * @line_number: line number to use while printing error
 *
 * Return: void
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;
	char c;

	if (stack == NULL || *stack == NULL) /* empty stack */
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	tail = getTail(stack); /* get the last node */
	c = tail->n; /* convert to character */
	if (tail->n < 0 || tail->n > 127) /* not ascii range */
	{
		dprintf(STDERR_FILENO,
				"L%u: can't pchar, value out of range\n", line_number);
		stackFree(stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", c); /* print character */
}

/**
 * pstr - prints the string starting at the top of the stack
 *
 * @stack: stack
 * @line_number: line number to use while printing error
 *
 * Return: void
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *node;

	(void)line_number; /* unused parameter */
	if (stack == NULL || *stack == NULL) /* empty stack */
	{
		putchar('\n');
		return;
	}

	node = getTail(stack);
	while (node != NULL)
	{
		/* if element is 0 or not within ascii range */
		if (node->n <= 0 || node->n > 127)
		{
			break; /* exit while loop */
		}
		printf("%c", node->n); /* format as character */
		node = node->prev; /* go to previous node */
	}
	putchar('\n'); /* print newline */
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
	num = node->n;

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
	stack_t *node, *temp;

	(void)line_number; /* unused parameter */
	temp = *stack; /* get last element */
	node = getTail(stack); /* get top element */

	*stack = temp->next; /* stack now points to second last element */
	temp->next = NULL;
	temp->prev = node;
	node->next = temp; /* last element becomes top */
	(*stack)->prev = NULL;
}
