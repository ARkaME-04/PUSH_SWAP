/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrian <tandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:12:23 by tandrian          #+#    #+#             */
/*   Updated: 2026/03/31 07:26:13 by tandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] != '\0' && s2[i] != '\0')
		&& (i < n - 1) && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	flagged(char *str)
{
	if (!str)
		return (0);
	if (ft_strncmp(str, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(str, "--medium", 9) == 0)
		return (2);
	if (ft_strncmp(str, "--complex", 10) == 0)
		return (3);
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return (4);
	if (ft_strncmp(str, "--bench", 8) == 0)
		return (5);
	return (0);
}

void	sort_adaptive(t_stack **a, t_stack **b, t_bench *bench)
{
	double	disorder;

	if (stack_size(*a) <= 10)
	{
		sort_simple(a, b, bench);
		return ;
	}
	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		sort_simple(a, b, bench);
	else if (disorder >= 0.2 && disorder < 0.5)
		sort_medium(a, b, bench);
	else
		sort_complex(a, b, bench);
}

void	check_flag(char *str, t_stack **a, t_stack **b, t_bench *bench)
{
	if (!str)
		sort_adaptive(a, b, bench);
	if (flagged(str) == 1)
		sort_simple(a, b, bench);
	else if (flagged(str) == 2)
		sort_medium(a, b, bench);
	else if (flagged(str) == 3)
		sort_complex(a, b, bench);
	else
		sort_adaptive(a, b, bench);
}
