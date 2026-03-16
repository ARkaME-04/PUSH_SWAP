/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:14:14 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/12 09:41:11 by tandrian         ###   ########.fr       */
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
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	conv = ft_atol(str);
	if (conv > INT_MAX || conv < INT_MIN)
		return (0);
	return (1);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}
