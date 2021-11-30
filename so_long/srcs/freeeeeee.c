/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeeeeee.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:00:42 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/29 22:00:43 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
void	map_free(t_data *data, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

static void	destroy_image(t_data *data)
{
	if (data->p != NULL)
		mlx_destroy_image(data->mlx, data->p);
	if (data->one != NULL)
		mlx_destroy_image(data->mlx, data->one);
	if (data->zero != NULL)
		mlx_destroy_image(data->mlx, data->zero);
	if (data->e != NULL)
		mlx_destroy_image(data->mlx, data->e);
	if (data->c != NULL)
		mlx_destroy_image(data->mlx, data->c);
}

void	best_free_jp(t_data *data, char *error)
{
	map_free(data, data->map_size);
	destroy_image(data);
	if (data->win != NULL)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx != NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (error != NULL)
		print_error(error);
}
