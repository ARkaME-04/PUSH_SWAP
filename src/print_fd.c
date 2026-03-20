/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrian <tandrian@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:05:03 by tandrian          #+#    #+#             */
/*   Updated: 2026/03/19 10:05:07 by tandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd((nbr % 10) + '0', fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}

void	ft_put_double(double n, int fd)
{
	int	decimal;
	int	integer;

	integer = (int)n;
	decimal = (int)((n - integer) * 100);
	if (decimal < 0)
		decimal = -decimal;
	ft_putnbr_fd(integer, fd);
	ft_putstr_fd(".", fd);
	if (decimal < 10)
		ft_putstr_fd("0", fd);
	ft_putnbr_fd(decimal, fd);
}
