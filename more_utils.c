/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:14:14 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/11 10:17:48 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int val)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->value = val;
	a->next = NULL;
	return (a);
}

void	add_bottom(t_stack **stack, t_stack *node)
{
	t_stack	*tmp;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

int	is_valid(char *str)
{
	int		i;
	long	conv;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	conv = ft_atol(str);
	if (conv >= INT_MAX || conv <= INT_MIN)
		return (0);
	return (1);
}

void	error_exit(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	parse_tab(char **tab, t_stack **a)
{
	int		i;
	long	n;
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
