/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:02:23 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/17 12:44:01 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	has_duplicate(t_stack *a, int n)
{
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

int	*stack_to_array(t_stack *a, int size)
{
	int	i;
	int	*res;

	res = malloc(size * sizeof(t_stack));
	if (!res)
		return (NULL);
	i = 0;
	while (a)
	{
		res[i] = a->value;
		a = a->next;
		i++;
	}
	return (res);
}

double	count_pairs(int *array, int size)
{
	int		i;
	int		j;
	double	mistakes;
	double	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs += 1;
			if (array[i] > array[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return (mistakes / total_pairs);
}

double	compute_disorder(t_stack *a)
{
	int		size;
	int		*array;
	double	mistakes;

	size = stack_size(a);
	array = stack_to_array(a, size);
	mistakes = count_pairs(array, size);
	free(array);
	return (mistakes);
}
