CLIENT	=	client
SERVER	=	server

LIBFT	=	libft.a
LIBDIR	=	./libft

SRCS	=	client.c

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc
CCFLAGS	=	-c #-Wall -Werror -Wextra 

all:	$(LIBFT) $(CLIENT)

$(LIBFT):
	make -C $(LIBDIR)

$(CLIENT):	client.o
	ar rcs $@ $^ $(LIBDIR)/*.o

