#include "minitalk.h"

static int	check_signum(int possible_status)
{
	static int	current_status = 0;

	if (possible_status)
		current_status = 1;
	else if (current_status)
	{
		current_status = 0;
		return (1);
	}
	return (0);
}

static void	send_bits(char chr, pid_t pid)
{
	int			bit;
	int			bit_send;

	bit = 0;
	while (bit <= 7)
	{
		bit_send = 1 & (chr >> bit++);
		if (bit_send == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else if (bit_send == 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		while (!check_signum(0))
			continue ;
	}
}

static void	srv_signal(int signum)
{
	if (signum == SIGUSR1)
		check_signum(1);
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr(MSG1);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1)
		exit(1);
	if ((signal(SIGUSR1, srv_signal) == SIG_ERR))
		exit(1);
	if ((signal(SIGUSR2, srv_signal) == SIG_ERR))
		exit(1);
	while (argv[2][i])
	{
		send_bits(argv[2][i], pid);
		i++;
	}
	send_bits('\0', pid);
	ft_putstr(MSG2);
	return (0);
}
