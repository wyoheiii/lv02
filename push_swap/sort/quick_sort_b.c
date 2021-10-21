/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:20:28 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/15 19:20:29 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	sort_idx_b_else(t_stack	**top, t_stack	**top2, t_count	*count, \
				t_pivot	pivot)
{
	write_command_a(top, top2, "pa");
	count->pa_count++;
	if ((*top)->idx < pivot.big)
	{
		write_command_a(top, top2, "ra");
		count->ra_count++;
	}
}

static void	sort_idx_b(t_stack	**top, t_stack	**top2, t_count	*count, \
	int	size)
{
	t_pivot	pivot;
	int		i;

	pivot.big = lst_in_array(*top2, size, 'b');
	pivot.low = lst_in_array(*top2, size, 's');
	i = 0;
	while (i < size && (*top2) != NULL)
	{
		if ((*top2)->idx < pivot.low)
		{
			write_command_b(top, top2, "rb");
			count->rb_count++;
		}
		else
			sort_idx_b_else(top, top2, count, pivot);
		i++;
	}
}

void	quick_sort_b(t_stack	**top, t_stack	**top2, int	size)
{
	t_count	count;

	if (size < 4)
	{
		if (size == 2)
		{
			if ((*top2)->idx < (*top2)->next->idx)
				write_command_b(top, top2, "sb");
		}
		else if (size == 3)
			quick_three_sort_b(top, top2);
		while (size > 0)
		{
			write_command_a(top, top2, "pa");
			size--;
		}
		return ;
	}
	initialization(&count);
	sort_idx_b(top, top2, &count, size);
	quick_sort_a(top, top2, count.pa_count - count.ra_count);
	reverse_idx(top, top2, count);
	quick_sort_a(top, top2, count.ra_count);
	quick_sort_b(top, top2, count.rb_count);
}
