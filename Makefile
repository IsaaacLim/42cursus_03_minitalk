CLIENT	=	client
SERVER	=	server

LIBDIR	=	libft
LIBFT	=	$(LIBDIR)/libft.a

SRCS	=	client.c server.c messages.c

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc
CFLAGS	=	#-Wall -Werror -Wextra 

all:	$(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	make -C $(LIBDIR)

$(CLIENT):	client.c messages.c
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

$(SERVER): server.c messages.c
	$(CC) $(CFLAGS) $^ $(LIBFT) -o $@

clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBDIR)
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re



