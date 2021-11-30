/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:54:33 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/29 21:54:34 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
t_list	*ft_lstmap(t_list	*lst, void	*(*f)(void *), void	(*del)(void *))
{
	t_list	*new;
	t_list	*ret;

	ret = NULL;
	if (f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst -> content));
		if (new == NULL)
		{
			ft_lstclear(&ret, del);
			return (NULL);
		}
		ft_lstadd_back(&ret, new);
		lst = lst->next;
	}
	return (ret);
}
