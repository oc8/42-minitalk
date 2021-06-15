#include "minitalk.h"

static void	action_sig_1(int sig, siginfo_t *siginfo, void *context)
{
	ft_putstr_fd("SIG1\n", 1); // comment acceder a la struct principale
	kill(siginfo->si_pid, SIGUSR2);
}

static void	action_sig_2(int sig, siginfo_t *siginfo, void *context)
{
	ft_putstr_fd("SIG2\n", 1);
	kill(siginfo->si_pid, SIGUSR2);
}

int	main(int argc, char *argv[])
{
	struct sigaction act;

	ft_bzero(&act, sizeof(act));
	ft_putstr_fd("\033[1m\033[32mPID : [", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("]\033[0m\n", 1);
	// if (sigaction(SIGUSR1, &act, NULL) < 0)
	// {
	// 	ft_putstr_fd("sigaction() error", 2);
	// 	return (1);
	// }
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &action_sig_1;
	if (sigaction(SIGUSR1, &act, NULL))
	{
		ft_putstr_fd("sigaction() error\n", 1);
		return (1);
	}
	act.sa_sigaction = &action_sig_2;
	if (sigaction(SIGUSR2, &act, NULL))
	{
		ft_putstr_fd("sigaction() error\n", 1);
		return (1);
	}
	// signal(SIGUSR1, &action_sig_1);
	// signal(SIGUSR2, &action_sig_2);
	while (42)
		pause();
	return (0);
}
