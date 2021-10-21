/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 09:48:02 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/16 09:56:19 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	three_sort_case(t_stack	**a, t_stack	**b, \
		int	case_number)
{
	if (case_number == 1)
		write_command_a(a, b, "sa");
	else if (case_number == 2)
	{
		write_command_a(a, b, "sa");
		write_command_a(a, b, "rra");
	}
	else if (case_number == 3)
		write_command_a(a, b, "ra");
	else if (case_number == 4)
	{
		write_command_a(a, b, "sa");
		write_command_a(a, b, "ra");
	}
	else if (case_number == 5)
		write_command_a(a, b, "rra");
}

void	three_sort_next(t_stack	**a, t_stack	**b)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	first = *a;
	second = (*a)->next;
	last = ft_lstlast(*a);
	if (first->idx > second->idx && last->idx > second->idx && \
			first->idx > last->idx)
		three_sort_case(a, b, 3);
	else if (second->idx > first->idx && second->idx > last->idx && \
			last->idx > first->idx)
		three_sort_case(a, b, 4);
	else if (second->idx > first->idx && second->idx > last->idx && \
			first->idx > last->idx)
		three_sort_case(a, b, 5);
}

void	three_sort(t_stack	**a, t_stack	**b)
{
	t_stack	*last;
	t_stack	*first;
	t_stack	*second;

	if ((*a)->next == NULL || (*a)->next->next == NULL)
		return ;
	first = *a;
	second = (*a)->next;
	last = ft_lstlast(*a);
	if (first->idx > second->idx && last->idx > second->idx && \
			last->idx > first->idx)
		three_sort_case(a, b, 1);
	else if (first->idx > second->idx && second->idx > last->idx && \
			first->idx > last->idx)
		three_sort_case(a, b, 2);
	else
		three_sort_next(a, b);
}
