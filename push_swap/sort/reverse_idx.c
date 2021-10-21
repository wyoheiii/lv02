/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_idx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:52:07 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/15 19:53:58 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	reverse_idx_fitst(t_stack	**a, t_stack	**b, t_count	count)
{
	int	j;

	j = 0;
	while (j < count.rb_count)
	{
		write_command_b(a, b, "rrb");
		j++;
	}
}

void	reverse_idx(t_stack	**a, t_stack	**b, t_count	count)
{
	int	j;

	j = 0;
	while (j < count.ra_count && j < count.rb_count)
	{
		write_command_double(a, b, "rrr");
		j++;
	}
	while (j < count.ra_count)
	{
		write_command_a(a, b, "rra");
		j++;
	}
	while (j < count.rb_count)
	{
		write_command_b(a, b, "rrb");
		j++;
	}
}
