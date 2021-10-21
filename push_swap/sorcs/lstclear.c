/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:46:08 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/15 17:46:09 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	ft_lstdelone(t_stack	*lst)
{
	if (lst == NULL)
		return ;
	free(lst);
	lst = NULL;
}

void	lstclear(t_stack	**top)
{
	t_stack	*tmp;

	if (top == NULL)
		return ;
	while (*top != NULL)
	{
		tmp = (*top)->next;
		ft_lstdelone(*top);
		*top = tmp;
	}
	*top = NULL;
}
