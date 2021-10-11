#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void 	ft_putstr(char *s)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					f;
	unsigned long int	r;

	i = 0;
	r = 0;
	f = 1;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			f = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
		if (r > 2147483647 && f == 1)
			return (-1);
		if (r > 2147483648 && f == -1)
			return (0);
	}
	return (r * f);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		nb = -1 * nb;
		ft_putchar('-');
	}
	if (nb < 10)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
