/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initi_structer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:42:33 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/25 11:12:54 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	initi_structer_map(t_maps *t_map)
{
	ft_bzero(t_map, sizeof(t_maps));
}

void	initi_struct_image_plyer(t_player *t_plyer)
{
	ft_bzero(t_plyer, sizeof(t_player));
	t_plyer->animation_speed = 5;
}

void	initi_structer_check_hase_characters(t_check_hase_charc *data_caracter)
{
	ft_bzero(data_caracter, sizeof(t_check_hase_charc));
}

void	initi_structer_window(t_window *win, t_maps *d_map)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
	{
		perror("\nError: Memory allocation failed\n");
		ft_free_map(d_map->map, d_map->rows);
		exit(EXIT_FAILURE);
	}
	initi_struct_image_plyer(player);
	ft_bzero(win, sizeof(t_window));
	win->t_plyer = player;
	win->t_map = d_map;
	win->player_x = d_map->player_x;
	win->player_y = d_map->player_y;
	win->lives = 1;
	win->clos_win = 1;
}
