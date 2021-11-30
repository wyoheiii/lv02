/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:00:28 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/30 13:00:45 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdio.h>
# define BUFFER_SIZE 10
typedef struct s_info
{
	char		*buf;
	char		*line;
	int			read_size;
}	t_info;
char	*get_next_line(int fd, int *malloc_flag);
char	*no_newline(char **save, int *malloc_flag);
#endif
