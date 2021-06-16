#include "minitalk.h"

static void	send_sig(int sig, int pid)
{
	if (sig == 1)
	{
		if (kill(pid, SIGUSR2))
		{
			ft_putstr_fd("kill() error\n", 2);
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR1))
		{
			ft_putstr_fd("kill() error\n", 2);
			exit(1);
		}
	}
	while (!received_sig(0))
		;
}

static int	which_sig(unsigned char *c, int nbr)
{
	if (*c >= nbr)
	{
		*c -= nbr;
		return (1);
	}
	return (0);
}

static void	send_char(unsigned char c, int pid)
{
	send_sig(which_sig(&c, 128), pid);
	send_sig(which_sig(&c, 64), pid);
	send_sig(which_sig(&c, 32), pid);
	send_sig(which_sig(&c, 16), pid);
	send_sig(which_sig(&c, 8), pid);
	send_sig(which_sig(&c, 4), pid);
	send_sig(which_sig(&c, 2), pid);
	send_sig(which_sig(&c, 1), pid);
}

void	send(char *str, int pid)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
	send_char('\0', pid);
}
