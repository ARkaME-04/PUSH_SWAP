/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 09:09:23 by rhrandri          #+#    #+#             */
/*   Updated: 2026/02/09 07:09:16 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putnbr(long n);
int	ft_putnbr_hexa(unsigned long n, char up);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr);

#endif
