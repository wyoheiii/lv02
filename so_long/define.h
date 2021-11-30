/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:00:32 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/30 12:55:10 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define H_POINTER_UP 1
# define H_POINTER_DOWN -1
# define W_POINTER_UP 1
# define W_POINTER_DOWN -1
# define FAILURE -1
# define SUCCESS 0
# define WIN_CLOSE 17
# define ESC_KEY 65307
# define W_KEY 119
# define S_KEY 115
# define A_KEY 97
# define D_KEY 100
# define AC_ERROR "usage:./so_long <map>"
# define MAP_NAME_ERROR "MAP NAME : *.ber"
# define EXTENSION_ERROR "EXTENSION : <.ber>"
# define MAP_ERROR_NEED_WALL "It should always be surrounded by a wall"
# define READ_ERROR "read error or malloc error or empty file"
# define MAP_CHAR_ERROR "only use :1 0 E P C"
# define MALLOC_ERROR "malloc error"
# define MAP_WALL_TOP_ERROR "top wall only use : 1"
# define MAP_WALL_BOTTOM_ERROR "bottom wall only use : 1"
# define MAP_WALL_SAID_ERROR "said wall only use : 1"
# define P_ERROR "many P or need P"
# define E_ERROR "many E or need E"
# define C_ERROR "need C"
# define SQUARE_ERROR "not square"
# define MLX_INIT_ERROR "mlx_init error"
# define NEW_WINDOW_ERROR "mlx_new_window error"
# define NEW_IMAGE_ERROR "mlx_new_image error"
# define XPM_ERROR "mlx_xpm_file_to_image error"
# define OVER_MAP "MAP SIZE OVER"
#endif