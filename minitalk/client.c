/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:26:34 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/27 17:18:52 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void	send(int	pid, char	c)
{
	int	i;
	int	bit;

	i = 8;
	while (i--)
	{
		usleep(70);
		bit = (c >> i) & 1;
		if (bit == 0)
			bit = kill(pid, SIGUSR1);
		else if (bit == 1)
			bit = kill(pid, SIGUSR2);
		if (bit == -1)
		{
			write(1, "Error\n", 6);
			exit(1);
		}
	}
}

void	send_message(char	*pid, char	*message)
{
	int	i;
	int	server_pid;

	i = 0;
	server_pid = ft_atoi(pid);
	if (server_pid < 100 || server_pid > 99999)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	while (message[i] != '\0')
	{
		send(server_pid, message[i]);
		i++;
	}
}

int	main(int	ac, char	**av)
{
	if (ac != 3)
	{
		write(1, "av 1[pid]av 2[message]\n", 23);
		exit(0);
	}
	send_message(av[1], av[2]);
	return (0);
}
