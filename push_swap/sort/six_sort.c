/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:56:26 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/15 20:01:12 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	serch_idx_low_point(t_stack	*top)
{
	long long	idx_stack;
	t_stack		*tmp;
	size_t		i;

	idx_stack = top->idx;
	tmp = top;
	while (top != NULL)
	{
		if (idx_stack > top->idx)
			idx_stack = top->idx;
		top = top->next;
	}
	top = tmp;
	i = 0;
	while (top != NULL)
	{
		if (idx_stack == top->idx)
			break ;
		top = top->next;
		i++;
	}
	return (i);
}

static void	six_sort_low_stack(t_stack	**a, t_stack	**b, \
		size_t	lst_size, size_t	serch_idx_point)
{
	serch_idx_point = lst_size - serch_idx_point;
	while (serch_idx_point > 0)
	{
		write_command_a(a, b, "rra");
		serch_idx_point--;
	}
	write_command_b(a, b, "pb");
}

static void	six_sort_high_stack(t_stack	**a, t_stack	**b, \
		size_t	serch_idx_point)
{
	while (serch_idx_point > 0)
	{
		write_command_a(a, b, "ra");
		serch_idx_point--;
	}
	write_command_b(a, b, "pb");
}

void	six_sort(t_stack	**a, t_stack	**b)
{
	size_t	lst_size;
	size_t	serch_idx_point;
	size_t	i;

	lst_size = ft_lstsize(*a);
	while (lst_size > 3)
	{
		serch_idx_point = serch_idx_low_point(*a);
		if (lst_size - serch_idx_point < 3)
			six_sort_low_stack(a, b, lst_size, serch_idx_point);
		else
			six_sort_high_stack(a, b, serch_idx_point);
		lst_size = ft_lstsize(*a);
	}
	three_sort(a, b);
	i = 0;
	while (i < 3 && (*b) != NULL)
	{
		write_command_a(a, b, "pa");
		i++;
	}
}
