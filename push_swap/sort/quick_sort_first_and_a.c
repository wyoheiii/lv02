/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_first_and_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:26:43 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/06 20:30:08 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	sort_idx_a_else(t_stack	**a, t_stack	**b, t_count	*count, \
		t_pivot	pivot)
{
	write_command_b(a, b, "pb");
	count->pb_count++;
	if ((*b)->idx > pivot.low)
	{
		write_command_b(a, b, "rb");
		count->rb_count++;
	}
}

static void	sort_idx_a(t_stack	**a, t_stack	**b, t_count	*count, \
		int	size)
{
	t_pivot	pivot;
	int		i;

	pivot.big = lst_in_array(*a, size, 'b');
	pivot.low = lst_in_array(*a, size, 's');
	if (pivot.low == 2147483648 || pivot.big == 2147483648)
	{
		lstclear(a);
		lstclear(b);
		write_error();
		exit(1);
	}
	i = 0;
	while (i < size && (*a) != NULL)
	{
		if ((*a)->idx > pivot.big)
		{
			write_command_a(a, b, "ra");
			count->ra_count++;
		}
		else
			sort_idx_a_else(a, b, count, pivot);
		i++;
	}
}

void	quick_sort_a(t_stack	**a, t_stack	**b, int	size)
{
	t_count	count;

	if (size < 4)
	{
		if (size == 2)
		{
			if ((*a)->idx > (*a)->next->idx)
				write_command_a(a, b, "sa");
			return ;
		}
		else if (size == 3)
			quick_three_sort_a(a, b);
		return ;
	}
	initialization(&count);
	sort_idx_a(a, b, &count, size);
	reverse_idx(a, b, count);
	quick_sort_a(a, b, count.ra_count);
	quick_sort_b(a, b, count.rb_count);
	quick_sort_b(a, b, count.pb_count - count.rb_count);
}

void	quicksort_a_first(t_stack	**a, t_stack	**b, int	size)
{
	t_count	count;

	if (size < 4)
	{
		if (size == 2)
		{
			if ((*a)->idx > (*a)->next->idx)
				write_command_a(a, b, "sa");
			return ;
		}
		else if (size == 3)
			quick_three_sort_a(a, b);
		return ;
	}
	initialization(&count);
	sort_idx_a(a, b, &count, size);
	reverse_idx_fitst(a, b, count);
	quicksort_a_first(a, b, count.ra_count);
	quick_sort_b(a, b, count.rb_count);
	quick_sort_b(a, b, count.pb_count - count.rb_count);
}
