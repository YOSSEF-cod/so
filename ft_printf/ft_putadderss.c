/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadderss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:53:56 by ybounite          #+#    #+#             */
/*   Updated: 2024/11/16 17:53:57 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printaddress(unsigned long adres)
{
	int	i;

	i = 0;
	i += ft_putstr("0x");
	if (adres == 0)
		i += ft_putchar('0');
	else
		i += ft_puthex_lowercase(adres);
	return (i);
}
