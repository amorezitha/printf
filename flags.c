#include "main.h"

/**
 * get_flags - calculate active flags
 * @format: Formatted string in which to print the argument
 * @i: take a parameter
 * Return: flags
 */

int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8 16 */
	int index, current_i;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		for (index = 0; FLAGS_CH[index] != '\0'; index++)
			if (format[current_i] == FLAGS_CH[index])
			{
				flags |= FLAGS_ARR[index];
				break;
			}

		if (FLAGS_CH[index] == 0)
		break;
	}

	*i = current_i - 1;

	return (flags);
}
