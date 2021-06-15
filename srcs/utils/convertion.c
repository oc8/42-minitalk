#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	long long	rs;
	int			i;
	int			neg;

	neg = 1;
	rs = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
		neg = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		rs = rs * 10 + (nptr[i++] - '0') * neg;
		if (rs > INT_MAX)
			return (INT_MAX);
		else if (rs < INT_MIN)
			return (INT_MIN);
	}
	return (rs);
}
