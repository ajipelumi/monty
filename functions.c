#include "monty.h"

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
