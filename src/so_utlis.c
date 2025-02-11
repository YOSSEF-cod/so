/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_utlis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:34:25 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/24 21:29:16 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calcu_how_many_coins(t_maps *t_map)
{
	int (x), (y), (total_coins);
	x = 0;
	total_coins = 0;
	while (t_map->map[x])
	{
		y = 0;
		while (t_map->map[x][y])
		{
			if (t_map->map[x][y] == 'C')
				total_coins++;
			y++;
		}
		x++;
	}
	return (total_coins);
}
