#include <stdio.h>
/**
* is_palindrome-checks whether or not a given unsigned integer is a palindrome
* @n:is the number to be checked
* return: 0
*/
int is_palindrome(unsigned long n)
	{
		unsigned long i, rev = 0;
		i = n;

		while (i != 0)
		{
			rev = rev * 10;
			rev = rev + i % 10;
			i = i / 10;
		}

	if (n == rev)
		return (1);
	else
		return (0);
}
