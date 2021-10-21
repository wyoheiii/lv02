/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:03:38 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/16 17:22:36 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	check_sorted(t_stack	**a, t_stack	**b)
{
	if (check_sort(*a) == -1)
		return ;
	select_sort(a, b);
}

static int	check_av(int	ac, char	**av)
{
	int	i;

	i = 1;
	if (ac > 1001)
		return (-1);
	while (i < ac)
	{
		if (check_digit(av[i]) == -1)
			return (-1);
		i++;
	}
	if (check_numeric(av, ac) == -1)
		return (-1);
	return (0);
}

static int	push_swap(int	ac, char	**av)
{
	t_stack	*a;
	t_stack	*new;
	t_stack	*b;
	int		i;

	i = 1;
	a = NULL;
	b = NULL;
	while (i < ac)
	{
		new = new_node(ft_atoi(av[i]));
		if (new == NULL || new->idx == 2147483648)
		{
			lstclear(&a);
			return (-1);
		}
		ft_lstadd_back(&a, new);
		i++;
	}
	check_sorted(&a, &b);
	lstclear(&a);
	lstclear(&b);
	return (0);
}

int	main(int	ac, char	**av)
{
	if (ac > 1)
	{
		if (check_av(ac, av) == -1)
		{
			write_error();
			return (0);
		}
		if (push_swap(ac, av) == -1)
		{
			write_error();
			return (0);
		}
	}
	return (0);
}
