CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PRINTF_DIR = ft_printf
LIBFT_PRINTF = $(LIBFT_PRINTF_DIR)/libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX = -lmlx -lXext -lX11

SRCS = src/get_next_line.c src/initi_structer.c src/so_long.c src/so_utlis.c \
		src/check_file_name.c src/full_maps.c src/check_maps.c src/check_map_utlis.c \
		src/check_flood_fill.c src/initialization_enverment.c src/texture_loader.c \
		src/handle_key_press_events.c src/control_key_press.c src/close_window.c src/update_player_animation.c \
		src/texture_loader_plyer2.c src/free_map.c  

BONUS_SRCS = bonus/get_next_line.c bonus/initi_structer.c bonus/so_long_bonus.c bonus/so_utlis.c \
		bonus/check_file_name.c bonus/full_maps.c bonus/check_maps.c bonus/check_map_utlis.c \
		bonus/check_flood_fill.c bonus/initialization_enverment.c bonus/texture_loader.c \
		bonus/handle_key_press_events.c bonus/control_key_press.c bonus/close_window.c bonus/update_player_animation.c \
		bonus/put_string_window.c bonus/updat_animatoin_bonus.c bonus/texture_loader_plyer2.c bonus/free_map.c  

OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)

NAME = so_long

NAME_BONUS = bons

all: $(LIBFT_PRINTF) $(LIBFT) $(NAME)

$(NAME_BONUS): $(BONUS_OBJ) $(LIBFT_PRINTF) $(LIBFT)
	touch bons
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(MLX) $(LIBFT_PRINTF) $(LIBFT) -o $(NAME)

$(LIBFT_PRINTF):
	@$(MAKE) -C $(LIBFT_PRINTF_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LIBFT_PRINTF) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	@$(MAKE) -C $(LIBFT_PRINTF_DIR) clean
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_PRINTF_DIR) fclean
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
