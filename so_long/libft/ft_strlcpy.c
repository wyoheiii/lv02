/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:55:36 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/29 21:55:36 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	if (dstsize == 0)
		return (len);
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
