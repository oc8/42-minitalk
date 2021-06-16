#include "minitalk.h"

int	received_sig(int act)
{
	static int	flag = 0;

	if (act)
		flag = 1;
	else if (flag)
	{
		flag = 0;
		return (1);
	}
	return (0);
}

static void	sig_action(int sig)
{
	if (sig == SIGUSR2)
		received_sig(1);
	else if (sig == SIGUSR1)
	{
		ft_putstr_fd("\nReceived !\n\n", 1);
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_putstr_fd("arg error\n", 2);
		return (1);
	}
	if (ft_atoi(argv[1]) <= 0)
	{
		ft_putstr_fd("invalid pid\n", 2);
		return (1);
	}
	signal(SIGUSR1, &sig_action);
	signal(SIGUSR2, &sig_action);
	send(argv[2], ft_atoi(argv[1]));
	while (42)
		pause();
	return (0);
}
