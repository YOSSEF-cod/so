/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader_plyer2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:47:06 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/24 15:41:26 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	texture_loader_plyer2(t_window *win)
{
	win->t_plyer->plyer_left[0] = mlx_xpm_file_to_image(win->mlx,
			"./textures/plyer/plyer_4.xpm",
			&win->img_w, &win->img_h);
	win->t_plyer->plyer_left[1] = mlx_xpm_file_to_image(win->mlx,
			"./textures/plyer/plyer_5.xpm",
			&win->img_w, &win->img_h);
	win->t_plyer->plyer_left[2] = mlx_xpm_file_to_image(win->mlx,
			"./textures/plyer/plyer_6.xpm",
			&win->img_w, &win->img_h);
	if (!win->t_plyer->plyer_left[0] || !win->t_plyer->plyer_left[1]
		|| !win->t_plyer->plyer_left[2])
		return (perror("\nError loading image plyer left !\n"), 1);
	win->t_plyer->plyer_right[0] = mlx_xpm_file_to_image(win->mlx,
			"./textures/plyer/plyer_7.xpm",
			&win->img_w, &win->img_h);
	win->t_plyer->plyer_right[1] = mlx_xpm_file_to_image(win->mlx,
			"./textures/plyer/plyer_8.xpm",
			&win->img_w, &win->img_h);
	win->t_plyer->plyer_right[2] = mlx_xpm_file_to_image(win->mlx,
			"./textures/plyer/plyer_9.xpm",
			&win->img_w, &win->img_h);
	if (!win->t_plyer->plyer_right[0] || !win->t_plyer->plyer_right[1]
		|| !win->t_plyer->plyer_right[2])
		return (perror("Error:\nloading image plyer right !\n"), 1);
	return (0);
}

int	texture_loader_plyer(t_window *win)
{
	win->t_plyer->plyer_back[0] = mlx_xpm_file_to_image(win->mlx,
			"./textures/plyer/plyer_10.xpm",
			&win->img_w, &win->img_h);
	win->t_plyer->plyer_back[1] = mlx_xpm_file_to_image(win->mlx,
			"./textures/plyer/plyer_11.xpm",
			&win->img_w, &win->img_h);
	win->t_plyer->plyer_back[2] = mlx_xpm_file_to_image(win->mlx,
			"./textures/plyer/plyer_12.xpm",
			&win->img_w, &win->img_h);
	if (!win->t_plyer->plyer_back[0] || !win->t_plyer->plyer_back[1]
		|| !win->t_plyer->plyer_back[2])
		return (perror("\nError loading image plyer back !\n"), 1);
	win->t_plyer->plyer_front[0] = mlx_xpm_file_to_image(win->mlx,
			"./textures/plyer/plyer_1.xpm",
			&win->img_w, &win->img_h);
	win->t_plyer->plyer_front[1] = mlx_xpm_file_to_image(win->mlx,
			"./textures/plyer/plyer_2.xpm",
			&win->img_w, &win->img_h);
	win->t_plyer->plyer_front[2] = mlx_xpm_file_to_image(win->mlx,
			"./textures/plyer/plyer_3.xpm",
			&win->img_w, &win->img_h);
	if (!win->t_plyer->plyer_front[0] || !win->t_plyer->plyer_front[1]
		|| !win->t_plyer->plyer_front[2])
		return (perror("\nError loading image plyer front !\n"), 1);
	return (0);
}

int	texture_loader_enemy2(t_window *win)
{
	win->imag_enemy[8] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_9.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[9] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_10.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[10] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_11.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[11] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_12.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[12] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_13.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[13] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_14.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[14] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_15.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[15] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_16.xpm", &win->img_w, &win->img_h);
	if (!win->imag_enemy[8] || !win->imag_enemy[9] || !win->imag_enemy[10]
		|| !win->imag_enemy[11] || !win->imag_enemy[12] || !win->imag_enemy[13]
		|| !win->imag_enemy[14] || !win->imag_enemy[15])
		return (perror("\nError loading image enemy2!\n"), 1);
	return (0);
}

int	texture_loader_enemy(t_window *win)
{
	win->imag_enemy[0] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_1.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[1] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_2.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[2] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_3.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[3] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_4.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[4] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_5.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[5] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_6.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[6] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_7.xpm", &win->img_w, &win->img_h);
	win->imag_enemy[7] = mlx_xpm_file_to_image(win->mlx,
			"./textures/enemy/enem_8.xpm", &win->img_w, &win->img_h);
	if (!win->imag_enemy[0] || !win->imag_enemy[1] || !win->imag_enemy[2]
		|| !win->imag_enemy[3] || !win->imag_enemy[4] || !win->imag_enemy[5]
		|| !win->imag_enemy[6] || !win->imag_enemy[7])
		return (perror("\nError loading image enemy!\n"), 1);
	return (0);
}
