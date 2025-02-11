/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:17:04 by ybounite          #+#    #+#             */
/*   Updated: 2024/11/16 17:17:11 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_character(const char *str, va_list list)
{
	int	res;

	res = 0;
	if (*str == 's')
		res += ft_putstr(va_arg(list, char *));
	else if (*str == 'c')
		res += ft_putchar(va_arg(list, int));
	else if (*str == 'p')
		res += ft_printaddress(va_arg(list, unsigned long));
	else if (*str == 'd' || *str == 'i')
		res += ft_putnbr(va_arg(list, int));
	else if (*str == 'x')
		res += ft_puthex_lowercase(va_arg(list, unsigned int));
	else if (*str == 'X')
		res += ft_puthex_uppercase(va_arg(list, unsigned int));
	else if (*str == 'u')
		res += ft_putunsigned(va_arg(list, unsigned int));
	else if (*str == '%')
		res += ft_putchar('%');
	return (res);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		total;
	va_list	list;

	i = 0;
	total = 0;
	va_start(list, format);
	if (!format || write(1, 0, 0) == -1)
	{
		va_end(list);
		return (-1);
	}
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			total += check_character(&format[i], list);
		}
		else
			total += ft_putchar(format[i]);
		i++;
	}
	va_end(list);
	return (total);
}
