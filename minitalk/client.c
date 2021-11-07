/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:26:34 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/07 13:22:05 by wyohei           ###   ########.fr       */
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

int	ft_isdigit(int	c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (-1);
}

int	check_digit(char	*str)
{
	size_t	i;
	int		flag;

	i = 0;
	if (ft_strlen(str) > 11)
		return (-1);
	if (str[0] == '-')
	{
		i++;
		if (!(str[1] >= '1' && str[1] <= '9'))
			return (-1);
	}
	if (!(str[0] >= '1' && str[0] <= '9'))
		return (-1);
	while (str[i] != '\0')
	{
		flag = ft_isdigit(str[i]);
		if (flag == -1)
			return (-1);
		i++;
	}
	return (1);
}

void	send_message_and_pid_check(char	*pid, char	*message)
{
	int			i;
	long long	server_pid;

	i = 0;
	if (check_digit(pid) == -1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	server_pid = ft_atoi(pid);
	if (server_pid < 100 || server_pid > 99998 || server_pid == 2147483648)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	while (message[i] != '\0')
	{
		send((int)server_pid, message[i]);
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
	send_message_and_pid_check(av[1], av[2]);
	return (0);
}
