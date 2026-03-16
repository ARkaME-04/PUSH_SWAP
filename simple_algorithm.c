/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:14:25 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/13 17:14:25 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *a)
{
	int	min;
	int	pos;
	int	min_pos;

	min = a->value;
	pos = 0;
	min_pos = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			min_pos = pos;
		}
		pos++;
		a = a->next;
	}
	return (min_pos);
}

static void	rotate_top(t_stack **a, int pos)
{
	int	size;
	int	i;

	i = 0;
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (i < pos)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < size - pos)
		{
			rra(a);
			i++;
		}
	}
}

static void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if ((top > mid && mid > bot))
	{
		sa(a);
		rra(a);
	}
	else if ((top < mid && mid > bot && top < bot))
	{
		rra(a);
		sa(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

void	sort_simple(t_stack **a, t_stack **b)
{
	while (stack_size(*a) > 3)
	{
		rotate_top(a, find_min_pos(*a));
		pb(a, b);
	}
	if (stack_size(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else
		sort_three(a);
	while (*b)
		pa(a, b);
}
