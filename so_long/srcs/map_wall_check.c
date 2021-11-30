/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_wall_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:01:02 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/30 11:09:15 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
static int	char_check(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != '0' && str[i] != 'P' && \
				str[i] != 'C' && str[i] != 'E')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

void	map_char_check(t_data *data)
{
	long long	i;

	i = 0;
	while (data->map_size > i)
	{
		if (char_check(data->map[i]) == -1)
		{
			map_free(data, data->map_size);
			print_error(MAP_CHAR_ERROR);
		}
		i++;
	}
}

void	top_and_bottom_wall_check(t_data *data)
{
	size_t	i;

	i = 0;
	while (data->map[0][i] != '\0')
	{
		if (data->map[0][i] != '1')
		{
			map_free(data, data->map_size);
			print_error(MAP_WALL_TOP_ERROR);
		}
		i++;
	}
	i = 0;
	while (data->map[data->map_size - 1][i] != '\0')
	{
		if (data->map[data->map_size - 1][i] != '1')
		{
			map_free(data, data->map_size);
			print_error(MAP_WALL_BOTTOM_ERROR);
		}
		i++;
	}
}

void	said_wall_check(t_data *data)
{
	long long	i;
	size_t		last;

	i = 0;
	while (i < data->map_size)
	{
		last = ft_strlen(data->map[i]);
		if (data->map[i][0] != '1' || data->map[i][last - 1] != '1')
		{
			map_free(data, data->map_size);
			print_error(MAP_WALL_SAID_ERROR);
		}
		i++;
	}
}
