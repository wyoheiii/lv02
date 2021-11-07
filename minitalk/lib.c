/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:14:36 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/07 13:12:56 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
static void	ft_putchar_fd(char	c, int	fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int	n, int	fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n * -1, fd);
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

void	ft_putstr_fd(char	*s, int	fd)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

long long	ft_atoi(const char	*str)
{
	size_t		i;
	long long	check;
	long long	total;

	check = 1;
	total = 0;
	i = 0;
	if (str[i] == '-')
	{
		check = check * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + str[i] - '0';
		if (total > INT_MAX && check == 1)
			return (2147483648);
		if (((total) * check) < INT_MIN && check == -1)
			return (2147483648);
		i++;
	}
	return (total * check);
}

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
