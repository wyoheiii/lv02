/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 22:00:52 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/29 22:35:32 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*no_newline(char **save, int *malloc_flag)
{
	char	*line;

	if (**save == '\0')
		return (NULL);
	line = ft_substr(*save, 0, ft_strlen(*save));
	if (line == NULL)
	{
		*malloc_flag = -1;
		return (NULL);
	}
	return (line);
}
