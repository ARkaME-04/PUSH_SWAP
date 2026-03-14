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

	i = 0;
	while (tab[i])
	{
		if (!is_valid(tab[i]))
			error_exit();
		n = ft_atol(tab[i]);
		if (n > INT_MAX || n < INT_MIN)
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

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->next->value < a->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}