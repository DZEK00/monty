#include "monty.h"

/**
 * is_num - checks if a value is a number
 *
 * @value: the value to check
 *
 * Return: 1 on success and 0 on failure
 */

int is_num(char *value)
{
	int i = 0;

	if (value[i] == '-')
		i++;

	while (value[i])
	{
		if (!isdigit(value[i]))
			return (0);
		i++;
	}

	return (1);
}
