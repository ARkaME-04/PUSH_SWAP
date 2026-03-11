/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:02:23 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/11 09:11:51 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\r' || c == '\n'
		|| c == '\f' || c == '\v' || c == ' ')
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	int		i;
	long	num;
	long	sign;

	num = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i] != '\0')
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
}

int	has_duplicate(t_stack *a, int n)
{
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}
