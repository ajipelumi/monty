#include "monty.h"

#include <stdlib.h>

/**
 * stackPush - add a number on the stack
 * @stack: stack
 * @num: number to add on the stack
 */
void stackPush(stack_t **stack, int num)
{
	stack_t *newNode, *hold;

	if (stack == NULL)
		return;

	newNode = malloc(sizeof(*newNode));
	if (newNode == NULL)
		return;
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
	if (node->prev != NULL)
		node->prev->next = NULL;
	else if (node->prev == NULL)
		*stack = NULL;
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
		return (NULL);

	node = *stack;
	while (node->next != NULL)
		node = node->next;

	return (node);
}

/**
 * stackFree - free the stack.
 * @stack: stack:
 */
void stackFree(stack_t **stack)
{
	stack_t *node, *temp;

	if (stack == NULL || *stack == NULL)
		return;

	node = *stack;

	while (node != NULL)
	{
					temp = node;
					node = node->next;
					free(temp);
					}

}
