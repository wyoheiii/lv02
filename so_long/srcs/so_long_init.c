/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:01:11 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/30 12:47:41 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
void	mlx_setup(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		best_free_jp(data, MLX_INIT_ERROR);
	data->win = mlx_new_window(data->mlx, data->map_str_size * \
	32, data->map_size * 32, "so_long");
	if (data->win == NULL)
		best_free_jp(data, NEW_WINDOW_ERROR);
}

static void	set_texture(t_data *data, t_img **texture, char *texture_path)
{
	int	h;
	int	w;

	*texture = mlx_xpm_file_to_image(data->mlx, texture_path, &w, &h);
	if (texture == NULL)
		best_free_jp(data, XPM_ERROR);
	(*texture)->width = w;
	(*texture)->height = h;
}

void	texture_init(t_data *data)
{
	set_texture(data, &data->p, "./textures/space_pirot.xpm");
	set_texture(data, &data->zero, "./textures/floor.xpm");
	set_texture(data, &data->one, "./textures/wall.xpm");
	set_texture(data, &data->e, "./textures/space_earth.xpm");
	set_texture(data, &data->c, "./textures/light_saver.xpm");
}
