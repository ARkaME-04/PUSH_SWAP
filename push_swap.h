/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 08:45:31 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/12 09:42:47 by tandrian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack_node	t_stack;

struct	s_stack_node
{
	t_stack	*next;
	int		value;
	int		rank;
};

void	swap(t_stack **head);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **src, t_stack **dst);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	rotate(t_stack **head);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	reverse(t_stack **tail);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	free_tab(char **tab);
void	parse_tab(char **tab, t_stack **a);
void	parse_args(int argc, char **argv, t_stack **a);
void	add_bottom(t_stack **stack, t_stack *node);
void	error_exit(void);
void	sort_simple(t_stack **a, t_stack **b);
void	free_stack(t_stack **a);

int		is_sorted(t_stack *a);
int		is_valid(char *str);
int		ft_isspace(int c);
int		has_duplicate(t_stack *a, int n);
int		*stack_to_array(t_stack *a, int size);
int		ft_isdigit(int c);
int		stack_size(t_stack *a);

double	compute_disorder(t_stack *a);
double	count_pairs(int *array, int size, double *total_pairs);

t_stack	*new_node(int val);

size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);

long	ft_atol(const char *nptr);

#endif
