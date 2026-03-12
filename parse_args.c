/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrian <tandrian@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:37:58 by tandrian          #+#    #+#             */
/*   Updated: 2026/03/12 09:40:54 by tandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_tab(char **tab, t_stack **a)
{
	int		i;
	long	n;

	i = 1;
	{
		if (!is_valid(tab[i]))
			error_exit();
		n = ft_atol(tab[i]);
		if (n > 2147483647 || n < -2147483648)
			error_exit();
		if (has_duplicate(*a, (int)n))
			error_exit();
		add_bottom(a, new_node((int)n));
		i++;
	}
}

void	parse_args(int argc, char **argv, t_stack **a)
{
	char	**split;

	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		parse_tab(split, a);
		free_tab(split);
	}
	else
		parse_tab(argv + 1, a);
}
