/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 09:50:12 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/17 09:39:18 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = (*head);
	*head = tmp;
}

void	sa(t_stack **a, t_bench *bench)
{
	swap(a);
	write(1, "sa\n", 3);
	if (bench)
	{
		bench->sa++;
		bench->total++;
	}
}

void	sb(t_stack **b, t_bench *bench)
{
	swap(b);
	write(1, "sb\n", 3);
	if (bench)
	{
		bench->sb++;
		bench->total++;
	}
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	if (bench)
	{
		bench->ss++;
		bench->total++;
	}
}
