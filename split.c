/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:51:33 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/03 14:03:16 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char *s, char c)
{
	int	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
	}
}