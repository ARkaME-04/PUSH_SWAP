/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 10:12:54 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/30 23:20:47 by rhrandri         ###   ########.fr       */
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
	parse_args(argc, argv, a);
}

char	*flag_name(char *flag, double disorder)
{
	if (!flag || flagged(flag) == 0)
	{
		if (disorder < 0.2)
			return ("Adaptive / O(n²)");
		else if (disorder >= 0.2 && disorder < 0.5)
			return ("Adaptive / O(n√n)");
		else
			return ("Adaptive / O(nlog n)");
	}
	if (flagged(flag) == 1)
		return ("Simple / O(n²)");
	else if (flagged(flag) == 2)
		return ("Medium / O(n√n)");
	else if (flagged(flag) == 3)
		return ("Complex / O(nlog n)");
	return ("Adaptive / O(nlog n)");
}

int	has_bench(int argc, char **argv)
{
	char	**split;
	int		j;
	int		i;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split && split[j])
		{
			if (flagged(split[j]) == 5)
			{
				free(split);
				return (1);
			}
			j++;
		}
		if (split)
			free_tab(split);
		i++;
	}
	return (0);
}

void	handle_sort(int argc, char **argv, t_ctx *ctx)
{
	char	*flag;
	double	disorder;

	flag = find_flag(argc, argv);
	disorder = compute_disorder(*ctx->a);
	check_flag(flag, ctx->a, ctx->b, ctx->bench);
	if (has_bench(argc, argv))
		print_bench(ctx->bench, disorder, flag);
	if (flag)
		free(flag);
}
