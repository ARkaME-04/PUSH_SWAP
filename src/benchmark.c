/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:12:54 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/24 08:48:36 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_bench(t_bench *bench)
{
	bench->pa = 0;
	bench->pb = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total = 0;
}

void	handle_input(int argc, char **argv, t_stack **a)
{
	if (flagged(argv[1]) == 5)
	{
		if (argc > 2 && flagged(argv[2]))
		{
			if (flagged(argv[2]) == 5)
				error_exit(a, NULL);
			parse_args(argc - 2, argv + 2, a);
		}
		else if (argc > 2)
			parse_args(argc - 1, argv + 1, a);
	}
	else if (flagged(argv[1]))
		parse_args(argc - 1, argv + 1, a);
	else
		parse_args(argc, argv, a);
}

char	*flag_name(char *flag, double disorder)
{
	if (flagged(flag) == 1)
		return ("Simple / O(n²)");
	else if (flagged(flag) == 2)
		return ("Medium / O(n√n)");
	else if (flagged(flag) == 3)
		return ("Complex / O(nlog n)");
	else
	{
		if (disorder < 0.2)
			return ("Adaptive / O(n²)");
		else if (disorder >= 0.2 && disorder < 0.5)
			return ("Adaptive / O(n√n)");
		else
			return ("Adaptive / O(nlog n)");
	}
}

void	handle_sort(char **argv, t_stack **a, t_stack **b, t_bench *bench)
{
	int		is_bench;
	char	*flag;
	double	disorder;

	is_bench = (flagged(argv[1]) == 5);
	if (is_bench)
		flag = argv[2];
	else
		flag = argv[1];
	disorder = compute_disorder(*a);
	check_flag(flag, a, b, bench);
	if (is_bench)
		print_bench(bench, disorder, flag);
}
