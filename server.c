#include "minitalk.h"

static void	write_chr(char chr)
{
	if (chr == '\0')
		ft_putchar('\n');
	else
		ft_putchar(chr);
}

static void	bits_converter(int signum, pid_t client)
{
	static char	chr;
	static int	bit;

	if (signum == SIGUSR1)
	{
		chr += (0 << bit++);
		if (bit == 8)
		{
			write_chr(chr);
			chr = 0;
			bit = 0;
		}
	}
	else if (signum == SIGUSR2)
	{
		chr += (1 << bit++);
		if (bit == 8)
		{
			write_chr(chr);
			chr = 0;
			bit = 0;
		}
	}
	if (kill(client, SIGUSR1) == -1)
		exit(1);
}

static void	sig_handler(int signum, siginfo_t *sig_info, void *sival_ptr)
{
	(void)sival_ptr;
	bits_converter(signum, sig_info->si_pid);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);
	ft_putstr("pid server ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	while (21)
		pause();
	return (1);
}
