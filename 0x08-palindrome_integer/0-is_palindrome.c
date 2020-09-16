#include "palindrome.h"
#include <stdio.h>

/**
* is_palindrome - Checks if number is a palindrome
* @n: Number to check
* Return: 1 if n is a palindrome, 0 if not
*/

int is_palindrome(unsigned long n)
{
	int last = 0;
	unsigned long reverse = 0;
	unsigned long temp = n;

	while (n != 0)
	{
		/* Get last digit in n */
		last = n % 10;

		/* Build up reverse by * 10 to move digit's place by 1*/
		reverse = (reverse * 10) + last;

		/* Remove last digit each loop until n is 0 */
		n /= 10;
	}
	if (reverse == temp)
	{
		return (1);
	}

	return (0);
}