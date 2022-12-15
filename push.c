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
	char *cmd;
	int num;

	/* get the second argument */
	cmd = strtok(NULL, " ");
	if (cmd == NULL) /* no argument */
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free(curLine);
		exit(EXIT_FAILURE);
	}
	num = strtol(cmd, NULL, 10); /* convert string to integer */
	if (num == 0) /* no digits */
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		free(curLine);
		exit(EXIT_FAILURE);
	}
	free(curLine);
	add_dnodeint_end(stack, num); /* add to list */
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
		dprintf(STDERR_FILENO, "%u: can't pop an empty stack\n", line_number);
		free(curLine);
		stackFree(stack);
		exit(EXIT_FAILURE);
	}

	stackPop(stack);
}
