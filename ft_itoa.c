#include "main.h"

static int ft_len_sign(int number, int *nonpositive_ptr)
{
	int len;

	if (number <= 0)
		*nonpositive_ptr = 1;
	else
		*nonpositive_ptr = 0;
	len = 1;
	while (number)
	{
		number /= 10;
		len++;
	}
	return (len + *nonpositive_ptr);
}

void ft_fill_string(char *string, int last,
					int number, int negative)
{
	while (number)
	{
		if (negative)
			string[last--] = 48 + ((number % 10) * (-1));
		else
			string[last--] = 48 + (number % 10);
		number /= 10;
	}
}

char *ft_itoa(int number)
{
	int len;
	int nonpositive;
	char *string;

	len = ft_len_sign(number, &nonpositive);
	string = calloc((size_t)(len), sizeof(char));
	if (!(string))
		return ((void *)0);
	if (number == 0)
		string[0] = '0';
	if (number < 0)
		string[0] = '-';
	ft_fill_string(string, (len - 2), number, nonpositive);
	return (string);
}