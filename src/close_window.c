/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:19:20 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/11 09:28:48 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_data_imag(t_window *win)
{
	int (i);
	i = 0;
	if (win->imag_wall)
		mlx_destroy_image(win->mlx, win->imag_wall);
	if (win->imag_floor)
		mlx_destroy_image(win->mlx, win->imag_floor);
	while (i < 3)
	{
		if (win->t_plyer->plyer_back[i])
			mlx_destroy_image(win->mlx, win->t_plyer->plyer_back[i]);
		if (win->t_plyer->plyer_front[i])
			mlx_destroy_image(win->mlx, win->t_plyer->plyer_front[i]);
		if (win->t_plyer->plyer_left[i])
			mlx_destroy_image(win->mlx, win->t_plyer->plyer_left[i]);
		if (win->t_plyer->plyer_right[i])
			mlx_destroy_image(win->mlx, win->t_plyer->plyer_right[i]);
		i++;
	}
}

void	free_data_window(t_window *win)
{
	int (i);
	i = 0;
	free_data_imag(win);
	while (i < 8)
	{
		if (win->imag_coin[i])
			mlx_destroy_image(win->mlx, win->imag_coin[i]);
		if (win->imag_exit[i])
			mlx_destroy_image(win->mlx, win->imag_exit[i]);
		i++;
	}
	if (win->imag_exit[8])
		mlx_destroy_image(win->mlx, win->imag_exit[8]);
}

int	close_window(t_window *win)
{
	free_data_window(win);
	if (win->mlx_win)
	{
		mlx_destroy_window(win->mlx, win->mlx_win);
		win->mlx_win = NULL;
	}
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
		win->mlx = NULL;
	}
	ft_free_map(win->t_map->map, win->t_map->rows);
	free(win->t_plyer);
	if (win->clos_win)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
	return (0);
}
