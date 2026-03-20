/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:49:03 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/19 11:53:41 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	count_bit(int size)
{
	int	i;

	i = 0;
	while (size > 0)
	{
		size /= 2;
		i++;
	}
	return (i);
}

void	sort_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	bit_size;
	int	bit;
	int	i;

	assign_ranks(*a);
	size = stack_size(*a);
	bit_size = count_bit(size);
	bit = 0;
	while (bit < bit_size)
	{
		i = 0;
		while (i < size)
		{
			if (((*a)->rank >> bit) & 1)
				ra(a, bench);
			else
				pb(a, b, bench);
			i++;
		}
		while (*b)
			pa(a, b, bench);
		bit++;
	}
	rotate_top_a(a, find_min_pos(*a), bench);
}
