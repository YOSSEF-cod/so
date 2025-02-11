/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:48:10 by ybounite          #+#    #+#             */
/*   Updated: 2024/11/16 17:48:13 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		res += ft_putchar(str[i]);
		i++;
	}
	return (res);
}
