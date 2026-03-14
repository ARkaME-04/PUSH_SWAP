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
	else if ((top > mid && mid > bot) || (top < mid && mid > bot && top < bot))
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

static int	find_insert_pos(t_stack *a, int val)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = a;
	while (tmp && tmp->next)
	{
		if (val > tmp->value && val < tmp->next->value)
			return (pos + 1);
		pos++;
		tmp = tmp->next; 
	}
	if (val > tmp->value)
		return (pos + 1);
	return (0);
}

void    sort_simple(t_stack **a, t_stack **b)
{
    int    pos;

    while (stack_size(*a) > 3)
        pb(a, b);
    printf("after pb, size a: %d\n", stack_size(*a));  // DEBUG
    sort_three(a);
    printf("after sort_three\n");  // DEBUG
    while (*b)
    {
        printf("b top: %d\n", (*b)->value);  // DEBUG
        pos = find_insert_pos(*a, (*b)->value);
        printf("insert pos: %d\n", pos);  // DEBUG
        rotate_top(a, pos);
        pa(a, b);
    }
}
