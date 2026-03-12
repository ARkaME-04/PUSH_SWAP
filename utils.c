/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:02:23 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/12 09:21:45 by tandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

double	compute_disorder(t_stack *a)
{
	int		size;
	int		*array;
	int		i;
	int		j;
	double	mistakes;
	double	total_pairs;

	size = stack_size(a);
	array = stack_to_array(a, size);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (array[j] != '\0')
		{
			if (array[i] < array[j])
				total_pairs += 1;
			else
				mistakes += 1;
			j++;
		}
		i++;
	}
	free(array);
	return (mistakes / total_pairs);
}