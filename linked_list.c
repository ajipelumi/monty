#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * add_dnodeint_end - adds a new node at the end of a stack_t list
 *
 * @head: pointer to the list
 * @n: node element
 *
 * Return: void
 */

void *add_dnodeint_end(stack_t **head, int n)
{
	stack_t *new = NULL, *temp;

	if (head !=  NULL)
	{
		/* allocate memory */
		new = malloc(sizeof(stack_t));
		if (new == NULL) /* if malloc fails */
		{
			return;
		}
		new->n = n; /* assign struct element */
		new->next = NULL;
		new->prev = NULL;

		temp = *head; /* copy address of head to temp */
		if (temp == NULL) /* no list exists */
		{
			*head = new; /* head now points to first node */
			return;
		}
		/* temp goes through list until temp->next is null */
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new; /* temp'/'*head points to new */
		new->prev = temp; /* prev points to temp'/'*head */
	}
}

/**
 * free_stack_tlist - frees a stack_t list
 *
 * @head: pointer to the list
 *
 * Return: void
 */

void free_stack_tlist(stack_t *head)
{
	stack_t *temp;

	while (head != NULL) /* loop through list */
	{
		temp = head;
		head = head->next; /* go to the next node */
		free(temp); /* free temp */
	}
	free(head); /* free head */
}
