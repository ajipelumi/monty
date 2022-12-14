#ifndef MONTY_H
#define MONTY_H

/* define macros for dprintf */
#define _GNU_SOURCE
#define _POSIX_C_SOURCE  200809L

/* including stdio.h for FILE type */
#define _GNU_SOURCE
#include <stdio.h>

/* macros */
/* #define MEMERR STDERR_FILENO, "Error: malloc failed\n" */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 *
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 *
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* declaring global variables */
extern FILE *file;
extern char *curLine;

/* push.c */
void push(stack_t **stack, unsigned int line_number);

/* pall.c */
void pall(stack_t **stack, unsigned int line_number);

<<<<<<< HEAD
/* linked_list.c */
void *add_dnodeint_end(stack_t **head, int n);
void free_stack_tlist(stack_t *head);
=======
/* functions.c */
void _strchr(char *str, char unsetChr, char setChr);

/* stack.h */
void stackPush(stack_t **stack, int num);
void stackPop(stack_t **stack);
void stackFree(stack_t **stack);
stack_t *getTail(stack_t **stack);

/* pint.c */
void pint(stack_t **stack, unsigned int line_numeer);
>>>>>>> origin/abdul

#endif
