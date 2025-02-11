/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_uppercas.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:16:44 by ybounite          #+#    #+#             */
/*   Updated: 2024/11/16 17:16:57 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex_uppercase(unsigned int n)
{
	char	*hex;
	int		res;

	hex = "0123456789ABCDEF";
	res = 0;
	if (n >= 16)
		res += ft_puthex_uppercase(n / 16);
	res += ft_putchar(hex[n % 16]);
	return (res);
}
