#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>

# define MSG1 "please, give me pid and message\n"
# define MSG2 "the message was sent\n"

void	ft_putnbr(int nb);
void	ft_putstr(char *s);
void	ft_putchar(char c);
int		ft_atoi(const char *str);

#endif