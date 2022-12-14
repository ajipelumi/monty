#ifndef MONTY_H
#define MONTY_H

/* including stdio.h for FILE type */
#include <stdio.h>

/* macros */
#define MEMERR STDERR_FILENO, "Error: malloc failed\n"

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

/**
 * functions declarations goes here
 * Name of source code for each function should be above the function.
 * e.g.
 * monty.c
 * int main(int argc, char *argv);
 */

/*
 * push.c */
void push(stack_t **stack, unsigned int line_number);

#endif
