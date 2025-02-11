/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybounite <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:17:39 by ybounite          #+#    #+#             */
/*   Updated: 2024/11/16 17:17:42 by ybounite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_puthex_lowercase(unsigned long n);
int	ft_puthex_uppercase(unsigned int n);
int	ft_putnbr(int n);
int	ft_putunsigned(unsigned long n);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_printaddress(unsigned long adres);//

#endif
