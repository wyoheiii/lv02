/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:00:17 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/30 13:17:45 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./minilibx-linux/mlx_int.h"
# include "./libft/libft.h"
# include "get_next_line.h"
# include "define.h"
# include "struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
void	texture_init(t_data *data);
void	mlx_setup(t_data *data);
void	move(t_data *data, int w_idx, int h_idx);
int		key_action(int key, t_data *data);
int		close_game(t_data *data);
void	map_char_check(t_data *data);
void	top_and_bottom_wall_check(t_data *data);
void	said_wall_check(t_data *data);
void	map_in_array(char *av, t_data *data);
void	map_check(t_data *data);
int		close_game(t_data *data);
int		key_action(int key, t_data *data);
void	best_free_jp(t_data *data, char *error);
void	map_free(t_data *data, size_t size);
int		draw_map(t_data *data);
void	print_error(char *error);
#endif
