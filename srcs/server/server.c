#include "minitalk.h"

static void	add_to_str(size_t i, size_t *max, char **str, char c)
{
	if (i >= *max)
	{
		*max *= 2;
		(*str) = ft_strmemadd(str, *max);
	}
	(*str)[i] = c;
}

static void	next_char(char **str, size_t *i, siginfo_t *siginfo)
{
	send_received_char(siginfo);
	send_received(siginfo);
	ft_putstr_fd(*str, 1);
	free(*str);
	*str = 0;
	*i = 0;
}

static void	sig_action(int sig, siginfo_t *siginfo, void *context)
{
	static char		c = 0;
	static size_t	count = 0;
	static size_t	i = 0;
	static char		*str = 0;
	static size_t	max = 8;

	(void)context;
	if (!str)
		str = ft_calloc(max, sizeof(char));
	if (sig == SIGUSR2)
		c += ft_pow(2, 7 - count);
	count++;
	if (count >= 8)
	{
		add_to_str(i, &max, &str, c);
		if (!c)
			next_char(&str, &i, siginfo);
		else
			i++;
		c = 0;
		count = 0;
	}
	if (str)
		send_received_char(siginfo);
}

static int	catch_sig(void)
{
	struct sigaction	act;

	ft_bzero(&act, sizeof(act));
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &sig_action;
	if (sigaction(SIGUSR1, &act, NULL))
	{
		ft_putstr_fd("sigaction() error\n", 1);
		return (1);
	}
	if (sigaction(SIGUSR2, &act, NULL))
	{
		ft_putstr_fd("sigaction() error\n", 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("arg error\n", 2);
		return (1);
	}
	print_pid();
	if (catch_sig())
		return (1);
	while (42)
		pause();
	return (0);
}
