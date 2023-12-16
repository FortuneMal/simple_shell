#include "shell.h"

/**
 * _strncpy - copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the amount of characters to be copied
 * Return: the pointer to the destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	/* Copy characters from src to dest */
	for (i = 0; src[i] != '\0' && i < n - 1; i++)
		dest[i] = src[i];

	/* Null-terminate the destination string */
	if (i < n)
		dest[i] = '\0';

	return (dest);
}

/**
 * _strncat - concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the amount of bytes to be maximally used
 * Return: the pointer to the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	/* Find the end of the destination string */
	for (i = 0; dest[i] != '\0'; i++)
		;

	/* Concatenate characters from src to dest */
	for (j = 0; src[j] != '\0' && j < n; i++, j++)
		dest[i] = src[j];

	/* Null-terminate the concatenated string */
	if (j < n)
		dest[i] = '\0';

	return (dest);
}

/**
 * _strchr - locates a character in a string
 * @s: the string to be parsed
 * @c: the character to look for
 * Return: a pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

