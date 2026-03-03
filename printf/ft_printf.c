/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:08:44 by rhrandri          #+#    #+#             */
/*   Updated: 2026/02/18 09:58:47 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(const char type, va_list vargs)
{
	if (type == 'c')
		return (ft_putchar(va_arg(vargs, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(vargs, char *)));
	else if (type == 'u')
		return (ft_putnbr(va_arg(vargs, unsigned int)));
	else if (type == 'i' || type == 'd')
		return (ft_putnbr(va_arg(vargs, int)));
	else if (type == 'x' || type == 'X')
		return (ft_putnbr_hexa(va_arg(vargs, unsigned int), type));
	else if (type == 'p')
		return (ft_putptr(va_arg(vargs, void *)));
	else if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	loop(const char *format, va_list vargs)
{
	int		len;
	int		check;

	len = 0;
	while (*format && format)
	{
		if (*format == '%')
		{
			check = ft_conversion(*(++format), vargs);
			if (check == -1 || !*format)
				return (-1);
			len += check;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			len++;
		}
		format++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	vargs;
	int		len;

	if (!format)
		return (-1);
	va_start(vargs, format);
	len = loop(format, vargs);
	va_end(vargs);
	return (len);
}
