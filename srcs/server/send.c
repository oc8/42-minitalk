#include "minitalk.h"

void	send_received_char(siginfo_t *siginfo)
{
	static int	before_pid;

	if (siginfo->si_pid)
		before_pid = siginfo->si_pid;
	if (kill(before_pid, SIGUSR2))
	{
		ft_putstr_fd("kill() SIGUSR2 error", 2);
		exit(1);
	}
}

void	send_received(siginfo_t *siginfo)
{
	if (kill(siginfo->si_pid, SIGUSR1))
	{
		ft_putstr_fd("kill() SIGUSR1 error", 2);
		exit(1);
	}
}
