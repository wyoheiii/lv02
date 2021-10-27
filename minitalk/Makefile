CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			server client
				
server:			server.c lib.c
				$(CC) -o server $(CFLAGS) server.c lib.c


client:			client.c lib.c
				$(CC) -o client $(CFLAGS) client.c lib.c

clean:
				$(RM) server.o client.o lib.o

fclean:			clean
				$(RM) server client

re:				fclean all

.PHONY:			all clean fclean re