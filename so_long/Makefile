
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
#L  dirをみる -l mlx mlxの.aを探しに行くつなげて.a省略 x11はパソコンの中にあるx11のライブラリとかの lmはマウスの方math.h
#しかし, C の標準関数の中には, 「数学関数」と呼ばれる関数群があり62, これらの実体は標準関数には
#入っていない. 数学関数ライブラリは UNIX の場合には通常は /usr/lib/libm.a であり, 数学関数ライ
#ブラリ63を必要とする場合には,のように, -lm というオプションをリンカに渡す必要がある64. 最後に, なぜ -lm オプションを最後につけ
#るかという理由を考えてみよう. 例えば, file1.o は関数 sin の呼び出しを含むとき,
#gcc file1.o file2.o -o target -lm
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