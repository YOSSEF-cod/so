SRCS = ft_putchar.c ft_putstr.c ft_putnbr.c ft_printf.c \
	    ft_puthex_uppercas.c  ft_puthex_lowercase.c ft_putunsigned_int.c ft_putadderss.c

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: $(OBJS) 