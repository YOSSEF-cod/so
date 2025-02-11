/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:44:21 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/24 15:36:28 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	texture_loader_exit2(t_window *win)
{
	win->imag_exit[5] = mlx_xpm_file_to_image(win->mlx,
			"./textures/clons/exit_6_back.xpm",
			&win->img_w, &win->img_h);
	win->imag_exit[6] = mlx_xpm_file_to_image(win->mlx,
			"./textures/clons/exit_7_black.xpm",
			&win->img_w, &win->img_h);
	win->imag_exit[7] = mlx_xpm_file_to_image(win->mlx,
			"./textures/clons/exit_8_black.xpm",
			&win->img_w, &win->img_h);
	win->imag_exit[8] = mlx_xpm_file_to_image(win->mlx,
			"./textures/clons/exit_9.xpm",
			&win->img_w, &win->img_h);
	if (!win->imag_exit[5] || !win->imag_exit[6]
		|| !win->imag_exit[7] || !win->imag_exit[8])
		return (perror("Error loading image exit 2"), 1);
	return (0);
}

int	texture_loader_exit(t_window *win)
{
	win->imag_exit[0] = mlx_xpm_file_to_image(win->mlx,
			"./textures/clons/exit.xpm",
			&win->img_w, &win->img_h);
	win->imag_exit[1] = mlx_xpm_file_to_image(win->mlx,
			"./textures/clons/exit_2.xpm",
			&win->img_w, &win->img_h);
	win->imag_exit[2] = mlx_xpm_file_to_image(win->mlx,
			"./textures/clons/exit_3.xpm",
			&win->img_w, &win->img_h);
	win->imag_exit[3] = mlx_xpm_file_to_image(win->mlx,
			"./textures/clons/exit_4.xpm",
			&win->img_w, &win->img_h);
	win->imag_exit[4] = mlx_xpm_file_to_image(win->mlx,
			"./textures/clons/exit_5.xpm",
			&win->img_w, &win->img_h);
	if (!win->imag_exit[0] || !win->imag_exit[1] || !win->imag_exit[2]
		|| !win->imag_exit[3] || !win->imag_exit[4]
		|| texture_loader_exit2(win))
		return (perror("Error loading image exit"), 1);
	return (0);
}

int	texture_loader_coins_open_window(t_window *win)
{
	win->imag_coin[0] = mlx_xpm_file_to_image(win->mlx,
			"./textures/coin/open_win_coin_1.xpm",
			&win->img_w, &win->img_h);
	win->imag_coin[1] = mlx_xpm_file_to_image(win->mlx,
			"./textures/coin/open_win_coin_2.xpm",
			&win->img_w, &win->img_h);
	win->imag_coin[2] = mlx_xpm_file_to_image(win->mlx,
			"./textures/coin/open_win_coin_3.xpm",
			&win->img_w, &win->img_h);
	if (!win->imag_coin[0] || !win->imag_coin[1] || !win->imag_coin[2])
		return (perror("Error:\nloading image open win coins  left !\n"), 1);
	return (0);
}

int	texture_loader_coins(t_window *win)
{
	win->imag_coin[3] = mlx_xpm_file_to_image(win->mlx,
			"./textures/coin/coin_1.xpm",
			&win->img_w, &win->img_h);
	win->imag_coin[4] = mlx_xpm_file_to_image(win->mlx,
			"./textures/coin/coin_2.xpm",
			&win->img_w, &win->img_h);
	win->imag_coin[5] = mlx_xpm_file_to_image(win->mlx,
			"./textures/coin/coin_3.xpm",
			&win->img_w, &win->img_h);
	win->imag_coin[6] = mlx_xpm_file_to_image(win->mlx,
			"./textures/coin/coin_4.xpm",
			&win->img_w, &win->img_h);
	win->imag_coin[7] = mlx_xpm_file_to_image(win->mlx,
			"./textures/coin/coin_5.xpm",
			&win->img_w, &win->img_h);
	if (!win->imag_coin[3] || !win->imag_coin[4] || !win->imag_coin[5]
		|| !win->imag_coin[6] || !win->imag_coin[7])
		return (perror("Error:\nloading loop image coins left !\n"), 1);
	return (0);
}

void	texture_loader(t_window *win)
{
	win->imag_wall = mlx_xpm_file_to_image(win->mlx,
			"./textures/wall.xpm",
			&win->img_w, &win->img_h);
	win->imag_floor = mlx_xpm_file_to_image(win->mlx,
			"./textures/floor.xpm",
			&win->img_w, &win->img_h);
	win->imag_lives = mlx_xpm_file_to_image(win->mlx,
			"./textures/lives.xpm",
			&win->img_w, &win->img_h);
	if (!win->imag_wall || !win->imag_floor || !win->imag_lives
		|| texture_loader_coins(win) || texture_loader_plyer(win)
		|| texture_loader_plyer2(win) || texture_loader_exit(win)
		|| texture_loader_coins_open_window(win) || texture_loader_enemy(win)
		|| texture_loader_enemy2(win))
	{
		perror("Error\nloading image\n");
		close_window(win);
		exit(EXIT_FAILURE);
	}
}
