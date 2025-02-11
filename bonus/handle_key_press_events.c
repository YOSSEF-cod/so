/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press_events.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:11:09 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/24 09:30:16 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_for_coins_exit(t_window *window)
{
	if (window->t_map->map[window->player_x][window->player_y] == 'C')
	{
		window->t_map->map[window->player_x][window->player_y] = '0';
		window->player_coins++;
	}
}

void	ft_number_of_movements(t_window *win, char c)
{
	if (c == 'd' || c == 's' || c == 'w' || c == 'a')
	{
		win->moves++;
		ft_printf("\nnumber of movements player : %d\n", win->moves);
	}
}

void	init_key_word(t_window *win, char c)
{
	ft_number_of_movements(win, c);
	if (c == 'd')
	{
		win->player_y += 1;
		win->t_plyer->is_moving = 1;
		win->t_plyer->direction = RIGTH;
	}
	else if (c == 's')
	{
		win->player_x += 1;
		win->t_plyer->is_moving = 1;
		win->t_plyer->direction = FRONT;
	}
	else if (c == 'w')
	{
		win->player_x -= 1;
		win->t_plyer->is_moving = 1;
		win->t_plyer->direction = BACK;
	}
	else if (c == 'a')
	{
		win->player_y -= 1;
		win->t_plyer->is_moving = 1;
		win->t_plyer->direction = LEFT;
	}
}

void	handle_key_press_events(int keycode, t_window *win)
{
	win->t_plyer->is_moving = 0;
	if ((keycode == 'D' || keycode == 'd')
		&& (win->t_map->map[win->player_x][win->player_y + 1] != '1'))
		init_key_word(win, 'd');
	if ((keycode == 'S' || keycode == 's')
		&& (win->t_map->map[win->player_x + 1][win->player_y] != '1'))
		init_key_word(win, 's');
	if ((keycode == 'W' || keycode == 'w')
		&& (win->t_map->map[win->player_x - 1][win->player_y] != '1'))
		init_key_word(win, 'w');
	if ((keycode == 'A' || keycode == 'a')
		&& (win->t_map->map[win->player_x][win->player_y - 1] != '1'))
		init_key_word(win, 'a');
}

void	handle_key_press_events_not_exit(int keycode, t_window *win)
{
	win->t_plyer->is_moving = 0;
	if ((keycode == 'D' || keycode == 'd')
		&& (win->t_map->map[win->player_x][win->player_y + 1] != '1')
		&& (win->t_map->map[win->player_x][win->player_y + 1] != 'E'))
		init_key_word(win, 'd');
	if ((keycode == 'S' || keycode == 's')
		&& (win->t_map->map[win->player_x + 1][win->player_y] != '1'
		&& (win->t_map->map[win->player_x + 1][win->player_y] != 'E')))
		init_key_word(win, 's');
	if ((keycode == 'W' || keycode == 'w')
		&& (win->t_map->map[win->player_x - 1][win->player_y] != '1'
		&& (win->t_map->map[win->player_x - 1][win->player_y] != 'E')))
		init_key_word(win, 'w');
	if ((keycode == 'A' || keycode == 'a')
		&& (win->t_map->map[win->player_x][win->player_y - 1] != '1'
		&& (win->t_map->map[win->player_x][win->player_y - 1] != 'E')))
		init_key_word(win, 'a');
}
