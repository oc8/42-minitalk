#include "minitalk.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = 0;
	if (!s)
		return ;
	while (s[len])
		len++;
	write(fd, s, len);
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

void	print_pid(void)
{
	ft_putstr_fd("\033[1m\033[32mPID : [", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\033[0m\n", 1);
}
