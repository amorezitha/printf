#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char character = va_arg(types, int);

	return (handle_write_char(character, buffer, flags, width, precision, size));
}

/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *stringArray = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (stringArray == NULL)
	{
		stringArray = "(null)";
		if (precision >= 6)
			str = " ";
	}

	while (stringArray[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &stringArray[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &stringArray[0], length);
			return (width);
		}
	}

	return (write(1, stringArray, length));
}

/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	int is_negative = 0;
	long int negative = va_arg(types, long int);
	unsigned long int number;

	negative = convert_size_number(negative, size);

	if (negative == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	number = (unsigned long int)negative;

	if (negative < 0)
	{
		number = (unsigned long int)((-1) * negative);
		is_negative = 1;
	}

	while (number > 0)
	{
		buffer[index--] = (number % 10) + '0';
		number /= 10;
	}

	index++;

	return (write_number(is_negative, index, buffer,
				flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of char printed.
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int numberOne, numberTwo, index, sum;
	unsigned int array[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	numberOne = va_arg(types, unsigned int);
	numberTwo = 2147483648; /* (2 ^ 31) */
	array[0] = numberOne / numberTwo;
	for (index = 1; index < 32; index++)
	{
		numberTwo /= 2;
		array[index] = (numberOne / numberTwo) % 2;
	}
	for (index = 0, sum = 0, count = 0; index < 32; index++)
	{
		sum += array[index];
		if (sum || index == 31)
		{
			char character = '0' + a[i];

			write(1, &character, 1);
			count++;
		}
	}
	return (count);
}
