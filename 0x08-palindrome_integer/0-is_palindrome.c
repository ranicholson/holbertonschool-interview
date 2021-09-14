#include "palindrome.h"


/**
 * is_palindrome - determines if the provided usigned long int is a palindrome
 * @n: Number to check palindrominess of
 * Return: 1 if it is palindrome otherwise 0
 */

int is_palindrome(unsigned long n)
{
	unsigned long numChecker = n, reversedNumber = 0;

	while (numChecker > 0)
	{
		reversedNumber = (numChecker % 10) + (reversedNumber * 10);
		numChecker = numChecker / 10;
	}

	if (n == reversedNumber)
		return (1);

	return (0);
}
