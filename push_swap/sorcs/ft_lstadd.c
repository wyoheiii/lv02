/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:45:56 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/15 17:45:57 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_stack	**lst, t_stack	*new)
{
	if (new == NULL || lst == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_stack	**lst, t_stack	*new)
{
	t_stack	*tmp;

	if (lst == NULL)
		return ;
	if (*lst != NULL)
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
	else
		*lst = new;
}
