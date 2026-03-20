/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrian <tandrian@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:01:34 by tandrian          #+#    #+#             */
/*   Updated: 2026/03/09 10:01:38 by tandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s2;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	s2 = malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	i = start;
	j = 0;
	while (j < len && s[i])
	{
		s2[j] = s[i];
		j++;
		i++;
	}
	s2[j] = '\0';
	return (s2);
}

static int	ft_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_count(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			s += ft_len(s, c);
		}
		else
			s++;
	}
	return (count);
}

static void	*free_str(char	**str, int i)
{
	while (i >= 0)
		free(str[i--]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		count;

	if (!s)
		return (NULL);
	i = 0;
	count = ft_count(s, c);
	str = malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			str[i] = ft_substr(s, 0, ft_len(s, c));
			if (!str[i++])
				return (free_str(str, i - 1));
			s += ft_len(s, c);
		}
		else
			s++;
	}
	str[i] = NULL;
	return (str);
}
