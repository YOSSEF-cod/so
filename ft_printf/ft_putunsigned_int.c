/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:49:04 by ybounite          #+#    #+#             */
/*   Updated: 2024/11/16 18:20:51 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunsigned(unsigned long n)
{
	int	res;

	res = 0;
	if (n >= 10)
		res += ft_putunsigned(n / 10);
	res += ft_putchar(n % 10 + '0');
	return (res);
}
