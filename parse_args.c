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
