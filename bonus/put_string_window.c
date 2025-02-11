/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:17:58 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/24 09:12:16 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	string_put_window(t_window *data, t_str_window *str)
{
	mlx_string_put(data->mlx, data->mlx_win, 0, 25, 0xFFFFFF, str->lives_str);
	mlx_string_put(data->mlx, data->mlx_win, 0, 50, 0xFFFFFF, str->coins_str);
	mlx_string_put(data->mlx, data->mlx_win, 0, 75, 0xFFFFFF, str->moves_str);
}

void	enter_string(t_window *data, t_str_window *str)
{
	str->num = 50;
	str->remove_nbr = ft_itoa(data->moves);
	str->coins_nbr = ft_itoa(data->player_coins);
	str->lives_str = ft_strdup("live : ");
	str->moves_str = ft_strjoin("Moves: ", str->remove_nbr);
	str->coins_str = ft_strjoin("coins: ", str->coins_nbr);
	if (!str->remove_nbr || !str->coins_nbr || !str->lives_str
		|| !str->moves_str || !str->coins_str)
	{
		ft_putstr_fd("Error for allocation !\n", 2);
		exit(1);
	}
}

void	render_status_panel(t_window *data)
{
	t_str_window	str;
	int				i;

	i = 1;
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imag_wall, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->imag_wall, 0, 64);
	enter_string(data, &str);
	string_put_window(data, &str);
	while (i <= data->lives)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->imag_lives, str.num, 10);
		str.num += 25;
		i++;
	}
	ft_free_string(&str);
}
