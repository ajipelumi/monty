#include "monty.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

/**
 * push - push a number on the stack
 *
 * @stack: stack
 * @line_number: line number to use while printing error
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *cmd, *ntr;
	int num;

	/* get the second argument */
	cmd = strtok(NULL, " ");
	if (cmd == NULL) /* no argument */
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		stackFree(stack);
		exit(EXIT_FAILURE);
	}
	num = strtol(cmd, &ntr, 10); /* convert string to integer */
	if (ntr == cmd) /* no digits */
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		stackFree(stack);
		exit(EXIT_FAILURE);
	}
	stackPush(stack, num); /* add to list */
}

/**
 * pop - removes the top element of the stack
 * @stack: stack
 * @line_number: line number to use while printing errors
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		stackFree(stack);
		exit(EXIT_FAILURE);
	}

	stackPop(stack);
}
