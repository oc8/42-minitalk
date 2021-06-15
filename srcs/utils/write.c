#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	n_long;

	n_long = (long)n;
	if (n_long < 0)
	{
		n_long *= -1;
		write(fd, "-", 1);
	}
	if (n_long < 10)
	{
		ft_putchar_fd(n_long + '0', fd);
	}
	else
	{
		ft_putnbr_fd(n_long / 10, fd);
		ft_putchar_fd(n_long % 10 + '0', fd);
	}
}
