/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:20:28 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/06 20:31:33 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	sort_idx_b_else(t_stack	**a, t_stack	**b, t_count	*count, \
				t_pivot	pivot)
{
	write_command_a(a, b, "pa");
	count->pa_count++;
	if ((*a)->idx < pivot.big)
	{
		write_command_a(a, b, "ra");
		count->ra_count++;
	}
}

static void	sort_idx_b(t_stack	**a, t_stack	**b, t_count	*count, \
	int	size)
{
	t_pivot	pivot;
	int		i;

	pivot.big = lst_in_array(*b, size, 'b');
	pivot.low = lst_in_array(*b, size, 's');
	if (pivot.low == 2147483648 || pivot.big == 2147483648)
	{
		lstclear(a);
		lstclear(b);
		write_error();
		exit(1);
	}
	i = 0;
	while (i < size && (*b) != NULL)
	{
		if ((*b)->idx < pivot.low)
		{
			write_command_b(a, b, "rb");
			count->rb_count++;
		}
		else
			sort_idx_b_else(a, b, count, pivot);
		i++;
	}
}

void	quick_sort_b(t_stack	**a, t_stack	**b, int	size)
{
	t_count	count;

	if (size < 4)
	{
		if (size == 2)
		{
			if ((*b)->idx < (*b)->next->idx)
				write_command_b(a, b, "sb");
		}
		else if (size == 3)
			quick_three_sort_b(a, b);
		while (size > 0)
		{
			write_command_a(a, b, "pa");
			size--;
		}
		return ;
	}
	initialization(&count);
	sort_idx_b(a, b, &count, size);
	quick_sort_a(a, b, count.pa_count - count.ra_count);
	reverse_idx(a, b, count);
	quick_sort_a(a, b, count.ra_count);
	quick_sort_b(a, b, count.rb_count);
}
