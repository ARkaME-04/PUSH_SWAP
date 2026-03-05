/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrian <tandrian@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 08:42:46 by tandrian          #+#    #+#             */
/*   Updated: 2026/03/05 10:29:35 by tandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack **tail)
{
	t_stack	*head;
	t_stack	*last;

	if (!*tail || !(*tail)->next)
		return ;
	head = *tail;
	while (head->next->next != NULL)
		head = head->next;
	last = head->next;
	last->next = *tail;
	*tail = last;
	head->next = NULL;
}

void	rra(t_stack **a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}
