/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:14:14 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/11 10:17:48 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int val)
{
	t_stack	*a;

	a = malloc(sizeof(t_stack));
	if (!a)
		return (NULL);
	a->value = val;
	a->next = NULL;
	return (a);
}
