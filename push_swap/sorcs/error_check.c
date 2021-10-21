/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:45:48 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/15 17:45:49 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	write_error(void)
{
	write(1, "Error\n", 6);
}

static int	ft_isdigit(int	c)
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
	while (str[i] != '\0')
	{
		flag = ft_isdigit(str[i]);
		if (flag == -1)
			return (-1);
		i++;
	}
	return (1);
}

static int	ft_memcmp(const void	*s1, const void	*s2, size_t	n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (n > 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
		n--;
	}
	return (0);
}

int	check_numeric(char	**str, int	ac)
{
	size_t	size;
	int		i;
	int		j;

	i = 1;
	while (i < ac - 1)
	{
		j = 1;
		j += i;
		while (j < ac)
		{
			size = ft_strlen(str[j]);
			if (ft_strlen(str[i]) > ft_strlen(str[j]))
				size = ft_strlen(str[i]);
			if (ft_memcmp(str[i], str[j], size) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}
