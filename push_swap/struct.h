/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:38:41 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/16 10:38:42 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_stack
{
	long long		idx;
	struct s_stack	*next;
}	t_stack;

typedef struct s_count
{
	int	ra_count;
	int	rb_count;
	int	pa_count;
	int	pb_count;
}	t_count;

typedef struct s_pivot
{
	long long	big;
	long long	low;
}	t_pivot;
#endif
