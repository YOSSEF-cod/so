/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:15:39 by ybounite          #+#    #+#             */
/*   Updated: 2024/11/16 17:57:00 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex_lowercase(unsigned long n)
{
	char	*hex;
	int		res;

	hex = "0123456789abcdef";
	res = 0;
	if (n >= 16)
		res += ft_puthex_lowercase(n / 16);
	res += ft_putchar(hex[n % 16]);
	return (res);
}
