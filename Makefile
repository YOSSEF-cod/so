NAME = so_long 
CC = cc
FLAGES = -Wall -Wextra -Werror -g3 -fsanitize=address 
LIBS =  -lmlx -lXext -lX11 -lm -lbsd

SIRC = so_long.c get_next_line.c get_next_line_utils.c check_valide_map.c
OBJS = $(SIRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGES) $(OBJS) $(LIBS) -o $(NAME)

clean :
	rm *.o
fclean: clean
	rm $(NAME)
