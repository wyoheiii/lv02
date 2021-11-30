/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:01:07 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/30 12:45:11 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
static void	put_image(t_data *data, t_img *tex)
{
	mlx_put_image_to_window(data->mlx, \
	data->win, tex, data->p_w * 32, data->p_h * 32);
}

static void	move_main(t_data *data, int w_idx, int h_idx)
{
	data->map[data->p_h][data->p_w] = '0';
	put_image(data, data->zero);
	data->p_h += h_idx;
	data->p_w += w_idx;
	put_image(data, data->p);
	if (data->map[data->p_h][data->p_w] == 'C')
	{
		put_image(data, data->zero);
		put_image(data, data->p);
		data->map[data->p_h][data->p_w] = '0';
		data->c_count--;
	}
	data->move_count++;
	printf("move count %ld\n", data->move_count);
	if (data->map[data->p_h][data->p_w] == 'E')
		close_game(data);
	data->map[data->p_h][data->p_w] = 'P';
}

void	move(t_data *data, int w_idx, int h_idx)
{
	if (data->map[data->p_h + h_idx][data->p_w + w_idx] != '1' && \
		(data->map[data->p_h + h_idx][data->p_w + w_idx] != 'E' \
			|| data->c_count == 0))
		move_main(data, w_idx, h_idx);
}
