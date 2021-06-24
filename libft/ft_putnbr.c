#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
			return ;
		}
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n /10);
	ft_putchar(n % 10 + '0');
}
