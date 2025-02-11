/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:31:06 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/23 15:15:10 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	flood_fill(t_maps *maps, int x, int y)
{
	if (x < 0 || x >= maps->rows || y < 0 || y >= maps->length_of_line
		|| maps->cpy_map[x][y] == '1' || maps->cpy_map[x][y] == 'F'
		|| maps->cpy_map[x][y] == 'X')
		return ;
	maps->cpy_map[x][y] = 'F';
	flood_fill(maps, x + 1, y);
	flood_fill(maps, x - 1, y);
	flood_fill(maps, x, y + 1);
	flood_fill(maps, x, y - 1);
}

void	player_position(t_maps *d_map)
{
	int	x;
	int	y;

	x = 0;
	while (x < d_map->rows)
	{
		y = 0;
		while (y < d_map->length_of_line)
		{
			if (d_map->map[x][y] == 'P')
			{
				d_map->player_x = x;
				d_map->player_y = y;
			}
			if (d_map->map[x][y] == 'E')
			{
				d_map->exit_x = x;
				d_map->exit_y = y;
			}
			y++;
		}
		x++;
	}
}

int	check_if_close_plyer(t_maps *d_map)
{
	int	x;
	int	y;

	x = 0;
	player_position(d_map);
	flood_fill(d_map, d_map->player_x, d_map->player_y);
	while (x < d_map->rows)
	{
		y = 0;
		while (y < d_map->length_of_line)
		{
			if (d_map->cpy_map[x][y] == 'C' || d_map->cpy_map[x][y] == 'E')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
