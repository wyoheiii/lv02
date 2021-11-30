/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:00:48 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/29 22:35:04 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	brainless_free(char	**str)
{
	free(*str);
	*str = NULL;
}

static size_t	check_n(char	*s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

static char	*get_line(char	*save_chr, char	**save, int *malloc_flag)
{
	char	*tmp;
	char	*line;

	line = ft_substr(*save, 0, check_n(*save));
	if (line == NULL)
	{
		*malloc_flag = -1;
		return (NULL);
	}
	tmp = ft_substr(*save, check_n(*save) + 1, ft_strlen(save_chr + 1));
	if (tmp == NULL)
	{
		*malloc_flag = -1;
		brainless_free(&line);
		return (NULL);
	}
	brainless_free(save);
	*save = tmp;
	return (line);
}

static char	*join_line(int fd, char **save, t_info *info, int *malloc_flag)
{
	char	*save_chr;
	char	*tmp;

	while (info->read_size > 0)
	{
		save_chr = ft_strchr(*save, '\n');
		if (save_chr != NULL)
			return (get_line(save_chr, save, malloc_flag));
		else
		{
			info->read_size = read(fd, info->buf, BUFFER_SIZE);
			if (info->read_size == -1)
				return (NULL);
			(info->buf)[info->read_size] = '\0';
			tmp = ft_strjoin(*save, info->buf);
			if (tmp == NULL)
			{
				*malloc_flag = -1;
				return (NULL);
			}
			brainless_free(save);
			*save = tmp;
		}
	}
	return (no_newline(save, malloc_flag));
}

char	*get_next_line(int	fd, int	*malloc_flag)
{
	static char	*save;
	t_info		info;

	info.buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (save == NULL)
		save = ft_substr("", 0, 0);
	if (info.buf == NULL || save == NULL)
	{
		*malloc_flag = -1;
		brainless_free(&save);
		brainless_free(&info.buf);
		return (NULL);
	}
	info.read_size = 1;
	info.line = join_line(fd, &save, &info, malloc_flag);
	brainless_free(&info.buf);
	if (info.line == NULL || info.read_size == -1 || info.read_size == 0)
	{
		brainless_free(&save);
		if (info.read_size == -1 || info.line == NULL)
			return (NULL);
	}
	return (info.line);
}
