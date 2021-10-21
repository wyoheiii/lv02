/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_three_sort_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:43:50 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/16 09:57:21 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	quick_three_sort_case_a_next(t_stack	**a, t_stack	**b, \
		int	case_number)
{
	if (case_number == 4)
	{
		write_command_a(a, b, "ra");
		write_command_a(a, b, "sa");
		write_command_a(a, b, "rra");
	}
	else if (case_number == 5)
	{
		write_command_a(a, b, "ra");
		write_command_a(a, b, "sa");
		write_command_a(a, b, "rra");
		write_command_a(a, b, "sa");
	}
}

static void	quick_three_sort_case_a(t_stack	**a, t_stack	**b, \
		int	case_number)
{
	if (case_number == 1)
		write_command_a(a, b, "sa");
	else if (case_number == 2)
	{
		write_command_a(a, b, "sa");
		write_command_a(a, b, "ra");
		write_command_a(a, b, "sa");
		write_command_a(a, b, "rra");
		write_command_a(a, b, "sa");
	}
	else if (case_number == 3)
	{
		write_command_a(a, b, "sa");
		write_command_a(a, b, "ra");
		write_command_a(a, b, "sa");
		write_command_a(a, b, "rra");
	}
	else
		quick_three_sort_case_a_next(a, b, case_number);
}

static void	quick_three_sort_a_next(t_stack	**a, t_stack	**b)
{
	t_stack	*sard;
	t_stack	*first;
	t_stack	*second;

	first = *a;
	second = (*a)->next;
	sard = (*a)->next->next;
	if (first->idx > second->idx && sard->idx > second->idx && \
		first->idx > sard->idx)
		quick_three_sort_case_a(a, b, 3);
	else if (second->idx > first->idx && second->idx > sard->idx && \
			sard->idx > first->idx)
		quick_three_sort_case_a(a, b, 4);
	else if (second->idx > first->idx && second->idx > sard->idx && \
			first->idx > sard->idx)
		quick_three_sort_case_a(a, b, 5);
}

void	quick_three_sort_a(t_stack	**a, t_stack	**b)
{
	t_stack	*sard;
	t_stack	*first;
	t_stack	*second;

	if ((*a)->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	sard = (*a)->next->next;
	if (first->idx > second->idx && sard->idx > second->idx && \
			sard->idx > first->idx)
		quick_three_sort_case_a(a, b, 1);
	else if (first->idx > second->idx && second->idx > sard->idx && \
			first->idx > sard->idx)
		quick_three_sort_case_a(a, b, 2);
	else
		quick_three_sort_a_next(a, b);
}
