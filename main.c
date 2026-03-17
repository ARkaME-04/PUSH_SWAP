/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 11:50:32 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/17 12:11:14 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_flag(char *str, t_stack **a, t_stack **b, t_bench *bench)
{
	if (flagged(str) == 1)
		sort_simple(a, b, bench);
	else if (flagged(str) == 2)
		sort_medium(a, b, bench);
	else if (flagged(str) == 3)
		sort_complex(a, b, bench);
	else
		sort_adaptive(a, b, bench);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	init_bench(&bench);
	handle_input(argc, argv, &a);
	if (!a || is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	handle_sort(argv, &a, &b, &bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
