/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 08:39:11 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/18 11:11:34 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/push_swap.h"

void	execute_rest(char *op, t_stack **a, t_stack **b)
{
	if (ft_strncmp(op, "rra\n", 4) == 0)
		reverse(a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		reverse(b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
	{
		reverse(a);
		reverse(b);
	}
	else if (ft_strncmp(op, "rr\n", 3) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else
		error_exit(a, b);
}

void	execute_op(char *op, t_stack **a, t_stack **b)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rotate(b);
	else
		execute_rest(op, a, b);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*op;

	op = get_next_line(0);
	while (op != NULL)
	{
		execute_op(op, a, b);
		free(op);
		op = get_next_line(0);
	}
	if (is_sorted(*a) && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &a);
	checker(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
