/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:27:46 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/25 10:44:46 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	is_rectangular(char **map, int rows)
{
	int	i;
	int	columns;
	int	check;

	i = 0;
	check = -1;
	while (i < rows)
	{
		columns = 0;
		while (map[i][columns] != '\n' && map[i][columns])
			columns++;
		if (map[i][columns] == '\n')
			columns--;
		if (check == -1)
			check = columns;
		if (check != columns)
			return (0);
		i++;
	}
	return (1);
}

int	check_bounderies(char **map, int rows, int columns)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < columns)
	{
		if (map[0][y] != '1' || map[rows - 1][y] != '1')
			return (0);
		y++;
	}
	while (x < rows)
	{
		if (map[x][0] != '1' || map[x][columns - 1] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_valid_characters(char **map, int rows, int columns)
{
	int	x;
	int	y;

	x = 0;
	while (x < rows)
	{
		y = 0;
		while (y < columns)
		{
			if (map[x][y] != '1' && map[x][y] != '0' && map[x][y] != 'E'
				&& map[x][y] != 'P' && map[x][y] != 'C' && map[x][y] != 'X')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	validate_map(t_maps *t_map)
{
	char *(str1), *(str2), *(str3), *(str4);
	str1 = "\nError:\n The map must contain at least one start ('P')";
	str2 = " and one exit ('E') or not collectible ('C').\n";
	str3 = "\nError:\nSome coins or the exit door are not reachable\n";
	str4 = "\nError:\n The number of rows or columns exceeds the limit\n";
	if (!is_sizelimit_maps(t_map->rows, t_map->length_of_line))
		return (ft_putstr_fd(str4, 2), 0);
	if (!is_rectangular(t_map->cpy_map, t_map->rows))
		return (ft_putstr_fd("\nError:\n The map is not rectangular.\n"
				, 2), 0);
	if (!check_bounderies(t_map->cpy_map, t_map->rows, t_map->length_of_line))
		return (ft_putstr_fd("\nError:\n The map is not enclosed by walls.\n"
				, 2), 0);
	if (!check_valid_characters(t_map->cpy_map, t_map->rows
			, t_map->length_of_line))
		return (ft_putstr_fd("\nError:\n The map contains invalid characters.\n"
				, 2), 0);
	if (!check_if_one_player_exit_collectible(t_map->cpy_map, t_map->rows
			, t_map->length_of_line))
		return (ft_putstr_fd(str1, 2), ft_putstr_fd(str2, 2), 0);
	if (!check_if_close_plyer(t_map))
		return (ft_putstr_fd(str3, 2), 0);
	return (1);
}

int	check_valid_maps(char *file, t_maps *t_map)
{
	t_map->fd = open(file, O_RDONLY);
	if (t_map->fd < 0)
		return (ft_putstr_fd("Error:\nUnable to open file!\n", 2), 0);
	t_map->rows = count_line(t_map->fd);
	if (t_map->rows == 0)
		return (close(t_map->fd),
			ft_putstr_fd("Error:\nthis file is empty!\n", 2), 0);
	t_map->fd = open(file, O_RDONLY);
	t_map->map = full_map(t_map->fd, t_map->rows);
	t_map->fd = open(file, O_RDONLY);
	t_map->cpy_map = full_map(t_map->fd, t_map->rows);
	if (!t_map->map || !t_map->cpy_map)
		return (ft_putstr_fd("Error:\n Failed to load map!\n", 2), 0);
	t_map->length_of_line = calcul_length_of_line(t_map->map);
	if (!validate_map(t_map))
	{
		ft_free_map(t_map->cpy_map, t_map->rows);
		ft_free_map(t_map->map, t_map->rows);
		return (ft_putstr_fd("Error:\nThe map is invalid!\n"
				, 2), 0);
	}
	ft_free_map(t_map->cpy_map, t_map->rows);
	return (1);
}
