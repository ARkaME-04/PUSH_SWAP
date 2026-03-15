/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 18:51:48 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/15 18:51:48 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;

	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

void	rank_node(t_stack *a)
{
	
}

void	assign_ranks(t_stack *a)
{
	int	size;
	int	*array;

	size = stack_size(a);
	array = (stack_to_array(a, size));
	sort_array(array, size);
}


void	medium_sort(t_stack **a, t_stack **b)
{

}