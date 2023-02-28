/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 20:48:47 by cgouiame          #+#    #+#             */
/*   Updated: 2023/02/27 17:49:03 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(int pid, char *str)
{
	int	i;
	int	n;
	int	shift;

	i = 0;
	while (str[i])
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
	ft_send(pid, av[2]);
}
