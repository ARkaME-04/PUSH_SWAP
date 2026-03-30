/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 11:18:47 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/30 18:40:24 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_ops1(t_bench *bench)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putstr_fd("\n", 2);
}

void	print_ops2(t_bench *bench)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_bench *bench, double disorder, char *flag)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_put_double((disorder * 100), 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(flag_name(flag, disorder), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(bench->total, 2);
	ft_putstr_fd("\n", 2);
	print_ops1(bench);
	print_ops2(bench);
}

int	ft_strlcpy(char *dst, const char *src, int dst_size)
{
	int	i;
	int	srclen;

	srclen = ft_strlen(src);
	if (dst_size == 0)
		return (srclen);
	i = 0;
	while (i < (dst_size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1) + 1;
	s2 = malloc(len * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1, len);
	return (s2);
}
