#include "monty.h"
#include <stdlib.h>
#include <unistd.h>

int fileFlag = 0;

/**
 * _strchr - replaces a character in a string with another character
 * @str: string to work with
 * @unsetChr: character to remove
 * @setChr: character to replace with
 */
void _strchr(char *str, char unsetChr, char setChr)
{
	unsigned int i = 0;

	for (i = 0; str[i]; ++i)
	{
		if (str[i] == unsetChr)
			str[i] = setChr;
	}
}

/**
 * initArgs - initialize arguments
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: void
 */

void initArgs(int argc, char *argv[])
{

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fileFlag = 1;
}
