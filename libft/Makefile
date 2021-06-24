NAME	=	libft.a

SRCS	=	ft_atoi.c ft_putchar.c ft_putnbr.c ft_putstr.c

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc
CCFLAGS	=	-c -Wall -Wextra -Werror -I

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rcs $@ $^

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re