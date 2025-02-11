/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:22:03 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/24 16:05:13 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	calcul_length_of_line(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\n' && map[0][i])
		i++;
	return (i);
}

int	count_line(int fd)
{
	int		count_line;
	char	*line;

	count_line = 0;
	line = get_next_line(fd);
	while (line)
	{
		count_line++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count_line);
}

int	is_sizelimit_maps(int rows, int clomse)
{
	if (rows > MAX_ROWS || clomse > MAX_COLS)
		return (0);
	return (1);
}

int	check_if_one_player_exit_collectible(char **map, int length, int rows)
{
	t_check_hase_charc	check;

	initi_structer_check_hase_characters(&check);
	while (check.x < length)
	{
		check.y = 0;
		while (check.y < rows)
		{
			if (map[check.x][check.y] == 'P')
				check.has_player++;
			else if (map[check.x][check.y] == 'E')
				check.hase_exit++;
			else if (map[check.x][check.y] == 'C')
				check.collectible++;
			check.y++;
		}
		check.x++;
	}
	return (check.has_player == 1 && check.hase_exit == 1
		&& check.collectible != 0);
}
