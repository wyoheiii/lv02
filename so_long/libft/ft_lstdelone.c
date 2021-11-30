/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:54:23 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/29 21:54:24 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	ft_lstdelone(t_list	*lst, void	(*del)(void*))
{
	if (lst == NULL)
		return ;
	if (del != NULL)
		del(lst -> content);
	free(lst);
}
