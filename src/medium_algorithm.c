/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:51:48 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/17 12:05:26 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	while (j < size)
	{
		i = j + 1;
		while (i < size)
		{
			if (array[j] > array[i])
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
			}
			i++;
		}
		j++;
	}
}

void	assign_ranks(t_stack *a)
{
	int		size;
	int		*array;
	int		i;
	t_stack	*tmp;

	size = stack_size(a);
	array = (stack_to_array(a, size));
	sort_array(array, size);
	tmp = a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tmp->value == array[i])
			{
				tmp->rank = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(array);
}

int	chunk_done(t_stack *a, int current_chunk)
{
	while (a)
	{
		if (a->rank >= current_chunk)
			return (0);
		a = a->next;
	}
	return (1);
}

int	find_max_pos(t_stack *b)
{
	int	max;
	int	max_pos;
	int	pos;

	max = -1;
	max_pos = 0;
	pos = 0;
	while (b)
	{
		if (b->rank > max)
		{
			max = b->rank;
			max_pos = pos;
		}
		pos++;
		b = b->next;
	}
	return (max_pos);
}

void	sort_medium(t_stack **a, t_stack **b, t_bench *bench)
{
	int	chunk_size;
	int	current_chunk;

	assign_ranks(*a);
	chunk_size = ft_sqroot(stack_size(*a));
	current_chunk = stack_size(*a) - chunk_size;
	while (*a)
	{
		if ((*a)->rank >= current_chunk)
			pb(a, b, bench);
		else
			ra(a, bench);
		if (chunk_done(*a, current_chunk))
			current_chunk -= chunk_size;
	}
	while (*b)
	{
		rotate_top_b(b, find_max_pos(*b), bench);
		pa(a, b, bench);
	}
}
