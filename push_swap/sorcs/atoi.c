/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:45:32 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/15 17:45:33 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
