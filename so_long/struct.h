/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:00:24 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/30 13:14:45 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_data
{
	size_t		move_count;
	char		**map;
	long long	map_size;
	long long	map_str_size;
	size_t		c_count;
	size_t		p_w;
	size_t		p_h;
	void		*mlx;
	void		*win;
	t_img		*p;
	t_img		*zero;
	t_img		*one;
	t_img		*e;
	t_img		*c;
}	t_data;
typedef struct s_flag
{
	size_t	p;
	size_t	e;
}	t_flag;
#endif
