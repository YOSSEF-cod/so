/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_key_press.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:50:30 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/24 20:57:29 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	chech_if_finsh_game(t_window *window)
{
	if (window->t_map->map[window->player_x][window->player_y] == 'E'
		&& window->total_coins == window->player_coins)
	{
		ft_putstr_fd("\n		YOU WIN			\n", 2);
		close_window(window);
	}
	if (window->t_map->map[window->player_x][window->player_y] == 'X')
	{
		ft_putstr_fd("\n		game ever 			\n", 2);
		close_window(window);
	}
}

void	control_handle_key_press(int keycode, t_window *win)
{
	if (win->total_coins == win->player_coins)
	{
		handle_key_press_events(keycode, win);
	}
	else
		handle_key_press_events_not_exit(keycode, win);
}

int	control_key_(int keycode, t_window *window)
{
	int (old_position_x), (old_position_y);
	if (keycode == ESCAPE)
		close_window(window);
	old_position_x = window->player_x;
	old_position_y = window->player_y;
	control_handle_key_press(keycode, window);
	update_player_animation(window);
	push_floor(window, old_position_x, old_position_y);
	check_for_coins_exit(window);
	render_status_panel(window);
	chech_if_finsh_game(window);
	return (1);
}
