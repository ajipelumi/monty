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
extern int fileFlag;

/* push.c */
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/* pall.c */
void pall(stack_t **stack, unsigned int line_number);

/* swap.c */
void swap(stack_t **stack, unsigned int line_number);

/* functions.c */
void _strchr(char *str, char unsetChr, char setChr);
void initArgs(int argc, char *argv[]);

/* stack.c */
void stackPush(stack_t **stack, int num);
void stackPop(stack_t **stack);
void stackFree(stack_t **stack);
stack_t *getTail(stack_t **stack);
int stackCount(stack_t **stack);

/* pint.c */
void pint(stack_t **stack, unsigned int line_number);

/* nop.c */
void nop(stack_t **stack, unsigned int line_number);

/* calc.c */
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/* extra.c */
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);


#endif
