/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:12:54 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/30 09:08:26 by rhrandri         ###   ########.fr       */
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

int	has_bench(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (flagged(argv[i]) == 5)
			return (1);
		i++;
	}
	return (0);
}

void	handle_sort(int argc, char **argv, t_ctx *ctx)
{
	int		is_bench;
	char	*flag;
	double	disorder;

	flag = find_flag(argc, argv);
	disorder = compute_disorder(*ctx->a);
	check_flag(flag, ctx->a, ctx->b, ctx->bench);
	if (has_bench(argc, argv))
		print_bench(ctx->bench, disorder, flag);
}
