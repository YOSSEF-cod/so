/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:17:44 by ybounite          #+#    #+#             */
/*   Updated: 2025/02/11 09:28:37 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_maps		t_map;
	t_window	win;

	initi_structer_map(&t_map);
	if (ac != 2)
		return (ft_putstr_fd("\nUsage: ./so_long <map_file> !\n", 2), 0);
	check_file_name(av[1]);
	if (!check_valid_maps(av[1], &t_map))
		return (ft_putstr_fd("\nFix the Error\n", 2), 1);
	initi_structer_window(&win, &t_map);
	initialization_enverment(&win, t_map);
	mlx_hook(win.mlx_win, KeyPress, KeyPressMask, control_key_, &win);
	mlx_hook(win.mlx_win, 17, 0, close_window, &win);
	mlx_loop(win.mlx);
}
