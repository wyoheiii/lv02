/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:00:38 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/30 12:52:14 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void	print_error(char *error)
{
	printf("Error\n%s\n", error);
	exit(1);
}

static void	extension_check(char *map)
{
	size_t	map_name_len;

	map_name_len = ft_strlen(map);
	if (map_name_len < 5)
		print_error(MAP_NAME_ERROR);
	else if (ft_memcmp(map + map_name_len - 4, ".ber", 4) != 0)
		print_error(EXTENSION_ERROR);
}

static void	get_map(char *av, t_data *data)
{
	extension_check(av);
	map_in_array(av, data);
	map_check(data);
}

static void	start_game(t_data *data)
{
	int	x;
	int	y;

	data->move_count = 0;
	mlx_setup(data);
	texture_init(data);
	draw_map(data);
	mlx_get_screen_size(data->mlx, &x, &y);
	if ((data->map_size * 32) > y || (data->map_str_size * 32) > x)
		best_free_jp(data, OVER_MAP);
	mlx_key_hook(data->win, key_action, data);
	mlx_hook(data->win, WIN_CLOSE, 0, close_game, data);
	mlx_hook(data->win, 12, 1L << 15, draw_map, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2)
	{
		get_map(av[1], &data);
		start_game(&data);
	}
	else
		print_error(AC_ERROR);
	return (0);
}
