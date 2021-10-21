/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 09:58:22 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/16 09:58:23 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static int	ft_strcmp(const char	*s1, const char	*s2)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	i = 0;
	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (dest[i] != '\0' && src[i] != '\0' && dest[i] == src[i])
		i++;
	return (dest[i] - src[i]);
}

void	write_command_a(t_stack	**top, t_stack	**top2,	char	*command)
{
	if (ft_strcmp(command, "sa") == 0)
	{
		ft_putstr(command);
		ft_sab(top);
	}
	if (ft_strcmp(command, "ra") == 0)
	{
		ft_putstr(command);
		ft_rab(top);
	}
	if (ft_strcmp(command, "rra") == 0)
	{
		ft_putstr(command);
		ft_rrab(top);
	}
	if (ft_strcmp(command, "pa") == 0)
	{
		ft_putstr(command);
		ft_pab(top2, top);
	}
}

void	write_command_b(t_stack **top, t_stack **top2, char *command)
{
	if (ft_strcmp(command, "sb") == 0)
	{
		ft_putstr(command);
		ft_sab(top2);
	}
	if (ft_strcmp(command, "rb") == 0)
	{
		ft_putstr(command);
		ft_rab(top2);
	}
	if (ft_strcmp(command, "rrb") == 0)
	{
		ft_putstr(command);
		ft_rrab(top2);
	}
	if (ft_strcmp(command, "pb") == 0)
	{
		ft_putstr(command);
		ft_pab(top, top2);
	}
}

void	write_command_double(t_stack	**top, t_stack	**top2, \
		char	*command)
{
	if (ft_strcmp(command, "ss") == 0)
	{
		ft_putstr(command);
		ft_sab(top);
		ft_sab(top2);
	}
	if (ft_strcmp(command, "rr") == 0)
	{
		ft_putstr(command);
		ft_rab(top);
		ft_rab(top2);
	}
	if (ft_strcmp(command, "rrr") == 0)
	{
		ft_putstr(command);
		ft_rrab(top);
		ft_rrab(top2);
	}
}
