#include "monty.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * add - add the top two element on the stack
 * @stack: stack
 * @line_number: line number to use while printing error
 */

void add(stack_t **stack, unsigned int line_number)
{
	int count, sum;
	stack_t *tail;

	count = stackCount(stack);
	if (count < 2) /* stack too short */
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		stackFree(stack);
		exit(EXIT_FAILURE);
	}

	/* add the last two elements */
	tail = getTail(stack);
	sum = tail->n;
	tail->prev->n += sum; /* store sum in previous node */
	stackPop(stack); /* remove last node */
}

/**
 * sub - subtracts the top two element on the stack
 * @stack: stack
 * @line_number: line number to use while printing error
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int count, sub;
	stack_t *tail;

	count = stackCount(stack);
	if (count < 2) /* stack too short */
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		stackFree(stack);
		exit(EXIT_FAILURE);
	}

	/* sub the last two elements */
	tail = getTail(stack);
	sub = tail->n;
	tail->prev->n -= sub; /* store subtraction from previous node */
	stackPop(stack); /* remove last node */
}

/**
 * divi - divides the second top element of the stack by the top element
 * @stack: stack
 * @line_number: line number to use while printing error
 */

void divi(stack_t **stack, unsigned int line_number)
{
	int count, top_num;
	stack_t *tail;

	count = stackCount(stack);
	if (count < 2) /* stack too short */
	{
		dprintf(STDERR_FILENO, "L%u: can't div, stack too short\n", line_number);
		stackFree(stack);
		exit(EXIT_FAILURE);
	}

	/* add the last two elements */
	tail = getTail(stack);
	top_num = tail->n; /* get top element */
	if (top_num == 0) /* top element is 0 */
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		stackFree(stack);
		exit(EXIT_FAILURE);
	}
	tail->prev->n /= top_num; /* store division in previous node */
	stackPop(stack); /* remove last node */
}
