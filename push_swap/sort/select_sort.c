/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:54:11 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/15 19:55:27 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	select_sort(t_stack	**a, t_stack	**b)
{
	int	av_len;

	av_len = ft_lstsize(*a);
	if (av_len == 0)
		return ;
	else if (av_len == 1)
		return ;
	else if (av_len == 2)
	{
		if ((*a)->idx > (*a)->next->idx)
			write_command_a(a, b, "sa");
	}
	else if (av_len >= 3 && 7 > av_len)
		six_sort(a, b);
	else if (6 < av_len)
		quicksort_a_first(a, b, av_len);
}
