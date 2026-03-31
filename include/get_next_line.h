/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:29:34 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/31 06:42:55 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*fill_stash(char *stash, char *buf);
char	*read_first_line(int fd, char *stash);
char	*get_line(char *stash);
char	*clean_line(char *stash);
char	*get_next_line(int fd);

void	*ft_calloc(unsigned int count, unsigned int size);
void	ft_bzero(void *s, unsigned int n);

int		ft_strlen_gnl(const char *str);

#endif
