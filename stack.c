#include "monty.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * stackPush - add a number on the stack
 * @stack: stack
 * @num: number to add on the stack
 */

void stackPush(stack_t **stack, int num)
{
	stack_t *newNode, *hold;

	if (stack == NULL)
	{
		return;
	}

	newNode = malloc(sizeof(*newNode));
	if (newNode == NULL) /* malloc fails */
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newNode->n = num;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (*stack == NULL)
	{ /* stack currently empty */
		*stack = newNode;
		return;
	}

	/* append node */
	hold = *stack;
	while (hold->next)
		hold = hold->next;

	newNode->prev = hold;
	hold->next = newNode;
}

/**
 * stackPop - remove the last item on the stack
 * @stack: stack
 */

void stackPop(stack_t **stack)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
		return;

	node = getTail(stack);
	if (node->prev != NULL) /* more than one element on the stack */
	{
		node->prev->next = NULL;
	}
	else if (node->prev == NULL) /* one element on the stack */
	{
		*stack = NULL;
	}
	free(node);
}

/**
 * getTail - get's the tail of the stack
 * @stack: stack
 *
 * Return: the tail of the stack
 * NULL: empty stack
 */

stack_t *getTail(stack_t **stack)
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		return (NULL);
	}

	node = *stack;
	while (node->next != NULL)
	{
		node = node->next; /* loop until last node */
	}
	return (node); /* return last node */
}

/**
 * stackFree - free the stack.
 * @stack: stack:
 */

void stackFree(stack_t **stack)
{
	stack_t *node, *temp;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}

	node = *stack;
	while (node != NULL) /* loop through stack */
	{
		temp = node;
		node = node->next;
		free(temp);
	}
}

/**
 * stackCount - get the number of elements in stack
 *
 * @stack: stack list
 *
 * Return: number of elements in the list
 */

int stackCount(stack_t **stack)
{
	stack_t *temp;
	int count = 0;

	if (stack == NULL || *stack == NULL) /* empty stack */
	{
		return (count);
	}

	temp = *stack;
	while (temp != NULL)
	{
		count++; /* increase count by 1 */
		temp = temp->next; /* go to the next node */
	}
	return (count);
}
