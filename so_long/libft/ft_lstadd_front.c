/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:54:16 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/29 21:54:16 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_lstadd_front(t_list	**lst, t_list	*new)
{
	if (new == NULL || lst == NULL)
		return ;
	new -> next = *lst;
	*lst = new;
}
