/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <ybounite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:29:29 by ybounite          #+#    #+#             */
/*   Updated: 2025/01/18 18:50:34 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**full_map(int fd, int rows)
{
	char	*line;
	char	**str;
	int		i;

	i = 0;
	str = malloc((rows + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		str[i] = line;
		line = get_next_line(fd);
		i++;
	}
	str[i] = NULL;
	close(fd);
	return (str);
}
