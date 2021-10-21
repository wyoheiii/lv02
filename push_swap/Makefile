
SRCS = push_swap.c sorcs/check_sorted.c sorcs/atoi.c sorcs/error_check.c sorcs/ft_longlong_swap.c \
		sorcs/ft_lstsize.c sorcs/ft_strlen.c sorcs/ft_lstadd.c\
		sorcs/ft_lstlast.c sorcs/lstclear.c sorcs/new_node.c sorcs/putstr.c \
		sort/ft_sort_command.c sort/initialization.c sort/median.c sort/quick_sort_b.c \
		sort/quick_sort_first_and_a.c sort/quick_three_sort_a.c sort/quick_three_sort_b.c \
		sort/reverse_idx.c sort/select_sort.c sort/three_sort.c sort/write_command.c sort/six_sort.c

OBJS		=   $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
NAME			= push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re