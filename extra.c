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

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	tail = getTail(stack); /* get the last node */
	c = tail->n; /* convert to character */
	if (tail->n < 0 && tail->n > 128) /* not ascii value */
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n", line_number);
		stackFree(stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", c); /* print character */
}
