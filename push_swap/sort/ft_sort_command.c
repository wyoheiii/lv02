/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:47:42 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/15 17:47:43 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	ft_sab(t_stack	**top)
{
	t_stack	*tmp;
	t_stack	*next_tmp;
	t_stack	*next_next_tmp;

	if (top == NULL || (*top)->next == NULL)
		return ;
	tmp = *top;
	next_tmp = (*top)->next;
	next_next_tmp = (*top)->next->next;
	tmp ->next = next_next_tmp;
	ft_lstadd_front(top, next_tmp);
}

void	ft_rab(t_stack	**top)
{
	t_stack	*last;
	t_stack	*keep_top_next_node;
	t_stack	*tmp;

	if (top == NULL || (*top)->next == NULL)
		return ;
	keep_top_next_node = *top;
	keep_top_next_node = keep_top_next_node->next;
	tmp = *top;
	last = ft_lstlast(tmp);
	last->next = tmp;
	tmp->next = NULL;
	*top = keep_top_next_node;
}

void	ft_rrab(t_stack	**top)
{
	t_stack	*last;
	t_stack	*tmp;
	t_stack	*last_prev;

	if (top == NULL || (*top)->next == NULL)
		return ;
	tmp = *top;
	last = ft_lstlast(tmp);
	last_prev = tmp;
	while (last_prev->next->next != NULL)
		last_prev = last_prev->next;
	last_prev->next = NULL;
	ft_lstadd_front(top, last);
}

void	ft_pab(t_stack	**pass_top, t_stack	**recive_top)
{
	t_stack	*tmp;
	t_stack	*pass;
	t_stack	*recive;

	if (pass_top == NULL)
		return ;
	tmp = (*pass_top)->next;
	pass = *pass_top;
	recive = *recive_top;
	if (recive == NULL)
	{
		ft_lstadd_front(recive_top, pass);
		pass->next = NULL;
		*recive_top = pass;
	}
	else
	{
		ft_lstadd_front(recive_top, pass);
		*recive_top = pass;
	}
	*pass_top = tmp;
}
