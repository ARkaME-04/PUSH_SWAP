/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrian <tandrian@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 10:02:26 by tandrian          #+#    #+#             */
/*   Updated: 2026/03/19 10:02:51 by tandrian         ###   ########.fr       */
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

void	rotate_top_a(t_stack **a, int pos, t_bench *bench)
{
	int	size;
	int	i;

	i = 0;
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while (i < pos)
		{
			ra(a, bench);
			i++;
		}
	}
	else
	{
		while (i < size - pos)
		{
			rra(a, bench);
			i++;
		}
	}
}

void	rotate_top_b(t_stack **b, int pos, t_bench *bench)
{
	int	size;
	int	i;

	i = 0;
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (i < pos)
		{
			rb(b, bench);
			i++;
		}
	}
	else
	{
		while (i < size - pos)
		{
			rrb(b, bench);
			i++;
		}
	}
}

static void	sort_three(t_stack **a, t_bench *bench)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a, bench);
	else if ((top > mid && mid > bot))
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if ((top < mid && mid > bot && top < bot))
	{
		rra(a, bench);
		sa(a, bench);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a, bench);
	else if (top < mid && mid > bot && top > bot)
		rra(a, bench);
}

void	sort_simple(t_stack **a, t_stack **b, t_bench *bench)
{
	while (stack_size(*a) > 3)
	{
		rotate_top_a(a, find_min_pos(*a), bench);
		pb(a, b, bench);
	}
	if (stack_size(*a) == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, bench);
	}
	else
		sort_three(a, bench);
	while (*b)
		pa(a, b, bench);
}
