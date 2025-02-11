/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updat_animatoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:20:39 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/09 18:08:08 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_door(t_window *win)
{
	mlx_put_image_to_window(win->mlx, win->mlx_win,
		win->imag_exit[win->animation_frame], win->t_map->exit_y * 64,
		win->t_map->exit_x * 64);
}

int	animation_coins(t_window *window)
{
	window->counter_coins++;
	if (window->counter_coins >= 15000)
	{
		window->coin_frame = (window->coin_frame + 1) % 4;
		update_coin_animation(window);
		window->counter_coins = 0;
	}
	return (0);
}

void	update_coin_animation(t_window *win)
{
	int (x), (y);
	x = 0;
	while (x < win->t_map->rows)
	{
		y = 0;
		while (y < win->t_map->length_of_line)
		{
			if (win->t_map->map[x][y] == 'C')
				mlx_put_image_to_window(win->mlx, win->mlx_win,
					win->imag_coin[3 + win->coin_frame], y * 64, x * 64);
			y++;
		}
		x++;
	}
}

int	updat_animatoin(t_window *window)
{
	animation_coins(window);
	if (window->total_coins == window->player_coins)
	{
		window->timer_player++;
		window->counter_coins++;
		if (window->timer_player >= 45000)
		{
			window->timer_player = 0;
			window->animation_frame++;
			if (window->counter_coins > 9)
				window->counter_coins = 3;
			if (window->animation_frame > 8)
				return (1);
			open_door(window);
		}
	}
	return (1);
}
