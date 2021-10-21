/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_three_sort_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:51:59 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/16 17:04:39 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	quick_three_sort_case_b_next(t_stack	**a, t_stack	**b, \
		int	case_number)
{
	if (case_number == 3)
	{
		write_command_b(a, b, "rb");
		write_command_b(a, b, "sb");
		write_command_b(a, b, "rrb");
	}
	else if (case_number == 4)
	{
		write_command_b(a, b, "sb");
		write_command_b(a, b, "rb");
		write_command_b(a, b, "sb");
		write_command_b(a, b, "rrb");
	}
	else if (case_number == 5)
		write_command_b(a, b, "sb");
}

static void	quick_three_sort_case_b(t_stack	**a, t_stack	**b, \
		int	case_number)
{
	if (case_number == 1)
	{
		write_command_b(a, b, "rb");
		write_command_b(a, b, "sb");
		write_command_b(a, b, "rrb");
		write_command_b(a, b, "sb");
	}
	else if (case_number == 2)
	{
		write_command_b(a, b, "sb");
		write_command_b(a, b, "rb");
		write_command_b(a, b, "sb");
		write_command_b(a, b, "rrb");
		write_command_b(a, b, "sb");
	}
	else
		quick_three_sort_case_b_next(a, b, case_number);
}

static void	quick_three_sort_b_next(t_stack	**a, t_stack	**b)
{
	t_stack	*sard;
	t_stack	*first;
	t_stack	*second;

	first = *b;
	second = (*b)->next;
	sard = (*b)->next->next;
	if (first->idx > second->idx && sard->idx > second->idx && \
			first->idx > sard->idx)
		quick_three_sort_case_b(a, b, 3);
	else if (second->idx > first->idx && second->idx > sard->idx && \
			sard->idx > first->idx)
		quick_three_sort_case_b(a, b, 4);
	else if (second->idx > first->idx && second->idx > sard->idx && \
			first->idx > sard->idx)
		quick_three_sort_case_b(a, b, 5);
}

void	quick_three_sort_b(t_stack	**a, t_stack	**b)
{
	t_stack	*sard;
	t_stack	*first;
	t_stack	*second;

	if ((*b)->next == NULL)
		return ;
	first = *b;
	second = (*b)->next;
	sard = (*b)->next->next;
	if (first->idx > second->idx && sard->idx > second->idx && \
			sard->idx > first->idx)
		quick_three_sort_case_b(a, b, 1);
	else if (first->idx < second->idx && second->idx < sard->idx && \
			first->idx < sard->idx)
		quick_three_sort_case_b(a, b, 2);
	else
		quick_three_sort_b_next(a, b);
}
