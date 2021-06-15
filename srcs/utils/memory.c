#include "minitalk.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = -1;
	while (n != 0)
	{
		str[++i] = '\0';
		n--;
	}
}
