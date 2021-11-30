/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:00:45 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/29 22:09:21 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
static void	put_image(t_data *data, long long i, long long j)
{
	if (data->map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->one, j * 32, i * 32);
	if (data->map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->e, j * 32, i * 32);
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->c, j * 32, i * 32);
	if (data->map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->p, j * 32, i * 32);
}

int	draw_map(t_data *data)
{
	long long	i;
	long long	j;

	i = 0;
	while (i < data->map_size)
	{
		j = 0;
		while (j < data->map_str_size)
		{
			put_image(data, i, j);
			j++;
		}
		i++;
	}
	return (0);
}

int	close_game(t_data *data)
{
	best_free_jp(data, NULL);
	exit(SUCCESS);
}

int	key_action(int key, t_data *data)
{
	if (key == ESC_KEY)
		close_game(data);
	else if (key == W_KEY)
		move(data, 0, H_POINTER_DOWN);
	else if (key == S_KEY)
		move(data, 0, H_POINTER_UP);
	else if (key == D_KEY)
		move(data, W_POINTER_UP, 0);
	else if (key == A_KEY)
		move(data, W_POINTER_DOWN, 0);
	return (0);
}
