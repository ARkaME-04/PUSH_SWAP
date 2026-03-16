/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 11:50:32 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/15 11:50:32 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_flag(char *str, t_stack **a, t_stack **b)
{
	if (flagged(str) == 1)
		sort_simple(a, b);
	else if (flagged(str) == 2)
		sort_medium(a, b);
	else if (flagged(str) == 3)
		sort_complex(a, b);
	else
		sort_adaptive(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (flagged(argv[1]))
		parse_args(argc - 1, argv + 1, &a);
	else
		parse_args(argc, argv, &a);
	if (is_sorted(a))
	{
		free_stack(&a);
		return (0);
	}
	check_flag(argv[1], &a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
