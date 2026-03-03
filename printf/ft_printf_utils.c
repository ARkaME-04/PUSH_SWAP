/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:47:37 by rhrandri          #+#    #+#             */
/*   Updated: 2026/02/09 07:39:12 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(long nb)
{
	int		len;
	int		aux;
	char	nm;

	len = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len += 1;
		nb = -nb;
	}
	nm = nb % 10 + '0';
	if (nb > 9)
	{
		aux = ft_putnbr(nb / 10);
		if (aux == -1)
			return (-1);
		len += aux;
	}
	if (write(1, &nm, 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putnbr_hexa(unsigned long n, char up)
{
	int		len;
	int		mod;
	int		aux;
	char	*base;

	mod = 0;
	len = 0;
	if (up == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
	{
		aux = ft_putnbr_hexa((n / 16), up);
		if (aux == -1)
			return (-1);
		len += aux;
	}
	mod = n % 16;
	if (write(1, &base[mod], 1) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (*str != '\0')
	{
		if (write(1, str, 1) == -1)
			return (-1);
		len++;
		str++;
	}
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	aux;

	len = 0;
	aux = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	if (ft_putstr("0x") == -1)
		return (-1);
	len += 2;
	aux = ft_putnbr_hexa((unsigned long)ptr, 'x');
	if (aux == -1)
		return (-1);
	len += aux;
	return (len);
}
