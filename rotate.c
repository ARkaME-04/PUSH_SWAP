/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:05:01 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/17 09:18:17 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*tail;

	if (!*head || !(*head)->next)
		return ;
	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *head;
	*head = ((*head)->next);
	tail->next->next = NULL;
}

void	ra(t_stack **a, t_bench *bench)
{
	rotate(a);
	write(1, "ra\n", 3);
	if (bench)
	{
		bench->ra++;
		bench->total++;
	}
}

void	rb(t_stack **b, t_bench *bench)
{
	rotate(b);
	write(1, "rb\n", 3);
	if (bench)
	{
		bench->rb++;
		bench->total++;
	}
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	if (bench)
	{
		bench->rr++;
		bench->total++;
	}
}
