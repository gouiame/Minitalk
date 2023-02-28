/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:24:43 by cgouiame          #+#    #+#             */
/*   Updated: 2023/02/28 13:13:29 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int sig)
{
	(void)sig;
	write(1, "Message reçu\n", 14);
}

void	ft_send(int pid, char *str)
{
	int	i;
	int	n;
	int	shift;

	i = 0;
	while (i <= ft_strlen(str))
	{
		shift = 0;
		while (shift < 8)
		{
			n = 128 >> shift;
			if ((n & str[i]) != 0)
			{
				kill(pid, SIGUSR2);
			}
			else
			{
				kill(pid, SIGUSR1);
			}
			shift++;
			usleep(800);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		exit(1);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
		exit(1);
	signal(SIGUSR2, handler);
	ft_send(pid, av[2]);
}
