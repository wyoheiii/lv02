/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:00:55 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/29 22:43:32 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	map_count_check(t_flag count, t_data *data)
{
	if (count.p != 1)
	{
		map_free(data, data->map_size);
		print_error(P_ERROR);
	}
	if (count.e != 1)
	{
		map_free(data, data->map_size);
		print_error(E_ERROR);
	}
	if (data->c_count == 0)
	{
		map_free(data, data->map_size);
		print_error(C_ERROR);
	}
}

static void	map_count(t_data *data, long long i, long long j, t_flag *count)
{
	if (data->map[i][j] == 'P')
	{
		data->p_w = j;
		data->p_h = i;
		count->p++;
	}
	if (data->map[i][j] == 'E')
		count->e++;
	if (data->map[i][j] == 'C')
		data->c_count++;
}

static void	map_p_e_c_check(t_data *data)
{
	long long	i;
	long long	j;
	t_flag		count;

	data->c_count = 0;
	count.e = 0;
	count.p = 0;
	i = 0;
	while (i < data->map_size)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			map_count(data, i, j, &count);
			j++;
		}
		i++;
	}
	map_count_check(count, data);
}

static void	map_square_check(t_data *data)
{
	long long	i;
	long long	len;

	i = 1;
	data->map_str_size = ft_strlen(data->map[0]);
	while (i < data->map_size)
	{
		len = ft_strlen(data->map[i]);
		if (data->map_str_size != len)
		{
			map_free(data, data->map_size);
			print_error(SQUARE_ERROR);
		}
		i++;
	}
}

void	map_check(t_data *data)
{
	map_square_check(data);
	map_char_check(data);
	top_and_bottom_wall_check(data);
	said_wall_check(data);
	map_p_e_c_check(data);
}
