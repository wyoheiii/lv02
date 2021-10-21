/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyohei <wyohei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 10:13:37 by wyohei            #+#    #+#             */
/*   Updated: 2021/10/16 10:35:30 by wyohei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "struct.h"

void		ft_putstr(char *s);
size_t		ft_strlen(const char *s);
int			check_digit(char *str);
t_stack		*new_node(long long idx);
void		ft_lstadd_front(t_stack **lst, t_stack *new);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		select_sort(t_stack **a, t_stack **b);
void		lstclear(t_stack **top);
void		ft_sab(t_stack **top);
void		ft_rab(t_stack **top);
void		ft_rrab(t_stack **top);
void		ft_pab(t_stack **pass_top, t_stack **recive_top);
void		write_command_a(t_stack **a, t_stack **b, char *command);
void		write_command_b(t_stack **a, t_stack **b, char *command);
void		write_command_double(t_stack **a, t_stack **b, char *command);
void		select_sort(t_stack **a, t_stack **b);
void		three_sort(t_stack **a, t_stack **b);
void		six_sort(t_stack **a, t_stack **b);
int			check_numeric(char **str, int ac);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void		ft_longlong_swap(long long *a, long long *b);
size_t		ft_strlen(const char *s);
void		quicksort_a_first(t_stack **a, t_stack **b, int size);
void		quick_sort_a(t_stack **a, t_stack **b, int size);
void		quick_sort_b(t_stack **a, t_stack **b, int size);
long long	lst_in_array(t_stack *a, int size, char c);
long long	ft_atoi(const char *str);
void		reverse_idx_fitst(t_stack **a, t_stack **b, t_count count);
void		reverse_idx(t_stack **a, t_stack **b, t_count count);
void		quick_three_sort_a(t_stack **a, t_stack **b);
void		quick_three_sort_b(t_stack **a, t_stack **b);
void		write_error(void);
void		initialization(t_count *count);
int			check_sort(t_stack *top);
#endif
