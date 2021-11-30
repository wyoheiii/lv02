/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:54:10 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/29 21:54:10 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_lstadd_back(t_list	**lst, t_list	*new)
{
	t_list	*tmp;

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
