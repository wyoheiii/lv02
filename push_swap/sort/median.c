/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:01:47 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/16 18:20:03 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static long long	get_median(long long	*array, int	array_size, char	c)
{
	int			size_half;
	int			size_half_half;
	long long	median;

	size_half = array_size / 2;
	size_half_half = size_half / 2;
	if (c == 's')
	{
		median = array[size_half_half];
		free(array);
		return (median);
	}
	else
	{
		median = array[size_half];
		free(array);
		return (median);
	}
}

static long long	bubble_sort(long long	*array, int	array_size, char	c)
{
	int	i;
	int	j;

	i = 0;
	while (i < array_size - 1)
	{
		j = array_size - 1;
		while (j >= i + 1)
		{
			if (array[j] < array[j - 1])
				ft_longlong_swap(&array[j], &array[j - 1]);
			j--;
		}
		i++;
	}
	return (get_median(array, array_size, c));
}

long long	lst_in_array(t_stack *top, int	size, char	c)
{
	long long	*array;
	int			i;

	i = 0;
	array = (long long *)malloc((sizeof(long long) * size));
	while (i < size && top != NULL)
	{
		array[i] = top->idx;
		top = top->next;
		i++;
	}
	return (bubble_sort(array, i, c));
}
