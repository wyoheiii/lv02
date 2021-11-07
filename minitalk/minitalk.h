/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 20:26:25 by wyohei            #+#    #+#             */
/*   Updated: 2021/11/07 13:14:00 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_signal
{
	int		bit;
	char	c;
}	t_signal;

void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
long long		ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
#endif
