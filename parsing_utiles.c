/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tandrian <tandrian@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 10:18:45 by tandrian          #+#    #+#             */
/*   Updated: 2026/03/07 10:30:57 by tandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;
	int	sign;

	num = 0;
	i = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - '0');
		i++;
	}
	return (num * sign);
}

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
