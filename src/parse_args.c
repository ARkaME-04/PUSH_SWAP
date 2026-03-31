/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrian <tandrian@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 07:14:21 by tandrian          #+#    #+#             */
/*   Updated: 2026/03/31 07:23:12 by tandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*find_flag(int argc, char **argv)
{
	char	*result;
	char	**split;
	int		j;
	int		i;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split && split[j])
		{
			if (flagged(split[j]) && flagged(split[j]) != 5)
			{
				result = ft_strdup(split[j]);
				free_tab(split);
				return (result);
			}
			j++;
		}
		if (split)
			free_tab(split);
		i++;
	}
	return (NULL);
}

void	parse_tab(char **tab, t_stack **a)
{
	int		i;
	long	n;

	i = 0;
	while (tab[i])
	{
		if (!flagged(tab[i]))
		{
			if (!is_valid(tab[i]))
			{
				free_tab(tab);
				error_exit(a, NULL);
			}
			n = ft_atol(tab[i]);
			if (n > INT_MAX || n < INT_MIN)
				error_exit(a, NULL);
			if (has_duplicate(*a, (int)n))
			{
				free_tab(tab);
				error_exit(a, NULL);
			}
			add_bottom(a, new_node((int)n));
		}
		i++;
	}
}

void	parse_args(int argc, char **argv, t_stack **a)
{
	char	**split;
	int		i;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split || !split[0])
		{
			if (split)
			{
				free_tab(split);
				error_exit(a, NULL);
			}
		}
		parse_tab(split, a);
		free_tab(split);
		i++;
	}
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

	if (!a || !*a)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}
