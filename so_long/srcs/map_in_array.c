/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_in_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:00:59 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/30 11:06:12 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	malloc_check(int malloc_flag, int map_size)
{
	if (malloc_flag == -1)
		print_error(MALLOC_ERROR);
	if (map_size < 2)
		print_error(MAP_ERROR_NEED_WALL);
}

static long long	get_map_size(char *av)
{
	int			fd;
	int			malloc_flag;
	char		*str;
	long long	map_size;

	malloc_flag = 0;
	map_size = 0;
	fd = open(av, O_RDONLY);
	str = get_next_line(fd, &malloc_flag);
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd, &malloc_flag);
		if (malloc_flag == -1)
		{
			free(str);
			print_error(MALLOC_ERROR);
		}
		map_size++;
	}
	free(str);
	malloc_check(malloc_flag, map_size);
	return (map_size);
}

void	map_in_array(char *av, t_data *data)
{
	int			fd;
	int			malloc_flag;
	long long	i;

	malloc_flag = 0;
	i = 0;
	fd = open(av, O_RDONLY);
	data->map_size = get_map_size(av);
	data->map = (char **)malloc(sizeof(char *) * data->map_size);
	while (i < data->map_size)
	{
		data->map[i] = get_next_line(fd, &malloc_flag);
		if (malloc_flag == -1)
		{
			map_free(data, i);
			print_error(MALLOC_ERROR);
		}
		i++;
	}
	close(fd);
}
