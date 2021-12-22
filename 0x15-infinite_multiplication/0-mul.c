#include "holberton.h"

/**
 * main - main function for program that muiltiplies two numbers of any size
 * @argc: Number of arguments being passed
 * @argv: Arguments being passed
 * Return: Success or failure
 */

int main(int argc, char **argv)
{
	int lenArg1, lenArg2, remainder, x, y, arg1Number, arg2Number;
	int *product;

	qualityAssurance(argc, argv);
	lenArg1 = poorMansStrlen(argv[1]);
	lenArg2 = poorMansStrlen(argv[2]);

	product = poorMansCalloc((lenArg1 + lenArg2), sizeof(*product));

	if (product == NULL)
		return (EXIT_FAILURE);

	for (x = lenArg1 - 1; x >= 0; x--)
	{
		remainder = 0;
		arg1Number = argv[1][x] - '0';

		for (y = lenArg2 - 1; y >= 0; y--)
		{
			arg2Number = argv[2][y] - '0';
			remainder += product[x + y + 1] + (arg1Number * arg2Number);
			product[x + y + 1] = remainder % 10;
			remainder /= 10;
		}

		if (remainder > 0)
			product[x + y + 1] += remainder;
	}

	arg1Number = product[0] == 0 ? 1 : 0;
	for (; arg1Number < lenArg1 + lenArg2; arg1Number++)
	{
		if (product[arg1Number] == 0)
			continue;
		_putchar(product[arg1Number] + '0');
	}
	_putchar('\n');

	free(product);
	return (EXIT_SUCCESS);
}


/**
 * qualityAssurance - function to check number of arguments and that only
 * digits are in passed arguments
 * @argc: Number of arguments passed
 * @argv: arguments passed
 * Return: 0 upon success
 */

void qualityAssurance(int argc, char **argv)
{
	int x, y;

	if (argc != 3)
	{
		poorMansPrintf("Error");
		exit(98);
	}

	for (x = 1; x < argc; x++)
	{
		for (y = 0; argv[x][y]; y++)
		{
			if (argv[x][y] < '0' || argv[x][y] > '9')
			{
				poorMansPrintf("Error");
				exit(98);
			}
		}
	}
}


/**
 * poorMansCalloc - Not allowed to use calloc, only malloc
 * @length: Length of array memory needs allocated for
 * @charSize: size of memory each character needs
 * @return void*
 */

void *poorMansCalloc(size_t length, size_t charSize)
{
	char *memChunk;
	size_t x;

	memChunk = malloc(length * charSize);

	if (memChunk == NULL)
		return (NULL);

	while (x < (length * charSize))
	{
		memChunk[x] = 0;
		x++;
	}

	return ((void *)memChunk);
}


/**
 * poorMansStrlen - not allowed to use strlen()
 * @string: string to return length of
 * Return: length of string
 */

size_t poorMansStrlen(char *string)
{
	size_t stringLength = 0;

	while (string[stringLength])
		stringLength++;

	return (stringLength);
}


/**
 * poorMansPrintf - not allowed to use printf(), only putchar
 * @string: String to print
 */

void poorMansPrintf(char *string)
{
	size_t charCount, x;

	charCount = poorMansStrlen(string);

	for (x = 0; x < charCount; x++)
		_putchar(string[x]);

	_putchar('\n');
}
