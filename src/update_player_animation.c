/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_animation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:10:40 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/24 21:29:41 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	push_floor(t_window *window, int x, int y)
{
	if (!(x == window->player_x && y == window->player_y))
		mlx_put_image_to_window(window->mlx, window->mlx_win,
			window->imag_floor, y * 64, x * 64);
}

void	draw_player(t_window *win)
{
	void	*cur_sprit;

	if (win->t_plyer->counter_player > 3)
		win->t_plyer->counter_player = 0;
	if (win->t_plyer->is_moving)
	{
		if (win->t_plyer->direction == FRONT)
			cur_sprit = win->t_plyer->plyer_front[win->t_plyer->cur_fram];
		else if (win->t_plyer->direction == BACK)
			cur_sprit = win->t_plyer->plyer_back[win->t_plyer->cur_fram];
		else if (win->t_plyer->direction == LEFT)
			cur_sprit = win->t_plyer->plyer_left[win->t_plyer->cur_fram];
		else if (win->t_plyer->direction == RIGTH)
			cur_sprit = win->t_plyer->plyer_right[win->t_plyer->cur_fram];
		mlx_put_image_to_window(win->mlx, win->mlx_win, cur_sprit,
			win->player_y * 64, win->player_x * 64);
	}
}

void	update_player_animation(t_window *window)
{
	window->t_plyer->counter_player++;
	window->t_plyer->cur_fram = (window->t_plyer->cur_fram + 1) % 3;
	draw_player(window);
}
