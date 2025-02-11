/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:50:03 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/25 10:53:35 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_filename_ber(char *file_name, char *str)
{
	int	i;

	i = 0;
	file_name = file_name + (ft_strlen(file_name) - 4);
	if (ft_strlen(file_name) == 0)
		return (0);
	while (file_name[i])
	{
		if (file_name[i] != str[i])
			return (0);
		i++;
	}
	return (1);
}

void	check_file_name(char *file_name)
{
	if (!file_name || !check_filename_ber(file_name, ".ber"))
	{
		ft_putstr_fd("\nErroe:\nfile name is incorrect!\n", 2);
		exit(EXIT_FAILURE);
	}
}
