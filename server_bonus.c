/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:08:02 by cgouiame          #+#    #+#             */
/*   Updated: 2023/02/28 13:49:09 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_check(unsigned char n, int pid)
{
	if (!n)
		kill(pid, SIGUSR2);
}

void	handle_signal(int signal, siginfo_t *info, void *p)
{
	static int				i;
	static unsigned char	n;
	static int				pid;
	int						sig;

	(void)p;
	if (pid != info->si_pid)
	{
		n = '\0';
		i = 0;
		pid = info->si_pid;
	}
	sig = 0;
	if (signal == SIGUSR2)
		sig = 1;
	n = n << 1;
	n = n | sig;
	i++;
	if (i == 8)
	{
		ft_check(n, pid);
		write(1, &n, 1);
		i = 0;
		n = '\0';
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
