/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 11:50:32 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/30 23:36:50 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_ctx	ctx;
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
		if (has_bench(argc, argv))
			print_bench(&bench, 0.0, find_flag(argc, argv));
		free_stack(&a);
		return (0);
	}
	ctx.a = &a;
	ctx.b = &b;
	ctx.bench = &bench;
	handle_sort(argc, argv, &ctx);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
