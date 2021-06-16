#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include "limits.h"

/*
**	client
*/
void	send(char *str, int pid);
int		received_sig(int act);

/*
**	server
*/
void	send_received_char(siginfo_t *siginfo);
void	send_received(siginfo_t *siginfo);

/*
**	utils
*/
void	print_pid(void);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
int		ft_pow(int nbr, int pow);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nbr, size_t size);
char	*ft_strmemadd(char **str, size_t new_size);

#endif
