#include "shell.h"
#include <ctype.h>
#include <string.h>

/**
 *trim- Trim leading and trailing whitespaces from a string.
 *@str: The input string to be trimmed.
 * Return: return character to be trimed.
 */

void *trim(char *str)
{

	char *end;

	if (str == NULL)
	{
		return (NULL);
	}


	while (isspace(*str))
	{
		str++;
	}


	if (*str == '\0')
	{
		return (str);
	}


	end = str + strlen(str) - 1;


	while (end > str && isspace(*end))
	{
		end--;
	}


	*(end + 1) = '\0';

	return (str);
}
