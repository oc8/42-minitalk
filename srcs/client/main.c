#include "minitalk.h"

static void	send_sig(int sig, int pid)
{
	if (sig == 1)
	{
		if (kill(pid, SIGUSR2))
		{
			ft_putstr_fd("kill() error", 2);
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR1))
		{
			ft_putstr_fd("kill() error", 2);
			exit(1);
		}
	}
	pause();
}

static int	which_sig(char *c, int nbr)
{
	if (*c >= nbr)
	{
		*c -= nbr;
		return (1);
	}
	return (0);
}

static void	send_char(char c, int pid)
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

static void	send(char *str, int pid)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		send_char(str[i], pid);
		i++;
	}
}

static void test()
{
	;
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_putstr_fd("arg error", 2);
		return (1);
	}
	signal(SIGUSR2, &test);
	send(argv[2], ft_atoi(argv[1]));
	return (0);
}
