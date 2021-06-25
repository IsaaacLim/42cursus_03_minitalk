#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void ft_createStrWithEOFChar(void)
{
	char c = 65;
	char n = '\n';
	char s[2];

	s[0] = 4;
	s[1] = n;
	ft_putstr(s);
}

int main()
{
	ft_createStrWithEOFChar();
}