/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 18:37:12 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/16 18:37:12 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (ft_strncmp(str, "--simple", 8) == 0)
		return (1);
	if (ft_strncmp(str, "--medium", 8) == 0)
		return (2);
	if (ft_strncmp(str, "--complex", 9) == 0)
		return (3);
	if (ft_strncmp(str, "--adaptive", 10) == 0)
		return (4);
	return (0);
}

void	sort_adaptive(t_stack **a, t_stack **b)
{
	double	disorder;

	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		sort_simple(a, b);
	else if (disorder >= 0.2 && disorder < 0.5)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}
