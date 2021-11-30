
NAME = so_long
SRCS = so_long.c srcs/get_next_line.c srcs/get_next_util.c srcs/so_long_init.c srcs/move.c \
		srcs/map_wall_check.c srcs/map_in_array.c srcs/map_error.c srcs/game.c srcs/freeeeeee.c
OBJS = $(SRCS:.c=.o)
CC	 = gcc
RM	 = rm -f
CFLAGS	= -Wall -Wextra -Werror 
LIBFTD = ./libft
LIBFT  = $(LIBFTD)/libft.a
MLX_NAME = minilibx-linux
MLXD = ./$(MLX_NAME)
MLX = $(MLXD)/libmlx.a
LINK = -L$(MLX_NAME) -lmlx -I$(MLX_NAME) -lXext -lX11 -lm

all:	 $(NAME)

$(NAME):	$(OBJS) $(LIBFT) $(MLX)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX)   $(LINK) -o $(NAME)

$(LIBFT):	$(LIBFTD)/*.c
			$(MAKE) -C $(LIBFTD)

$(MLX):		
		$(MAKE) -C $(MLXD)

clean:
			$(RM) $(OBJS)
			$(MAKE) -C $(LIBFTD) clean
			$(MAKE) -C $(MLXD) clean


fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)

re:			fclean $(NAME)

.PHONY:		all clean fclean re