/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader_plyer2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:47:06 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/24 21:29:20 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
