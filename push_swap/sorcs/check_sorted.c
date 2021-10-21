/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:45:42 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/16 18:20:15 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	free_array(long long	*array, int	flag)
{
	free(array);
	if (flag == -1)
		return (-1);
	else
		return (1);
}

static int	check_sorted(long long	*array, int	array_size)
{
	int	i;
	int	j;

	i = 0;
	if (array_size < 2)
		return (free_array(array, -1));
	while (i < array_size - 1)
	{
		j = array_size - 1;
		while (j >= i + 1)
		{
			if (array[j] < array[j - 1])
				return (free_array(array, 1));
			j--;
		}
		i++;
	}
	return (free_array(array, -1));
}

int	check_sort(t_stack	*top)
{
	int			size;
	int			i;
	long long	*array;

	size = ft_lstsize(top);
	array = (long long *)malloc((sizeof(long long) * size));
	i = 0;
	while (i < size && top != NULL)
	{
		array[i] = top->idx;
		top = top->next;
		i++;
	}
	return (check_sorted(array, i));
}
