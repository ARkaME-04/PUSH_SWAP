/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhrandri <rhrandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 08:45:31 by rhrandri          #+#    #+#             */
/*   Updated: 2026/03/30 18:40:14 by rhrandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack_node	t_stack;

struct	s_stack_node
{
	t_stack	*next;
	int		value;
	int		rank;
};

typedef struct s_bench
{
	int	ss;
	int	sa;
	int	sb;
	int	pa;
	int	pb;
	int	rr;
	int	ra;
	int	rb;
	int	rrr;
	int	rra;
	int	rrb;
	int	total;
}	t_bench;

typedef struct s_ctx
{
	t_stack	**a;
	t_stack	**b;
	t_bench	*bench;
}	t_ctx;

void	swap(t_stack **head);
void	sa(t_stack **a, t_bench *bench);
void	sb(t_stack **b, t_bench *bench);
void	ss(t_stack **a, t_stack **b, t_bench *bench);
void	push(t_stack **src, t_stack **dst);
void	pa(t_stack **a, t_stack **b, t_bench *bench);
void	pb(t_stack **b, t_stack **a, t_bench *bench);
void	rotate(t_stack **head);
void	ra(t_stack **a, t_bench *bench);
void	rb(t_stack **b, t_bench *bench);
void	rr(t_stack **a, t_stack **b, t_bench *bench);
void	reverse(t_stack **head);
void	rra(t_stack **a, t_bench *bench);
void	rrb(t_stack **b, t_bench *bench);
void	rrr(t_stack **a, t_stack **b, t_bench *bench);
void	free_tab(char **tab);
void	parse_tab(char **tab, t_stack **a);
void	parse_args(int argc, char **argv, t_stack **a);
void	add_bottom(t_stack **stack, t_stack *node);
void	error_exit(t_stack **a, t_stack **b);
void	sort_simple(t_stack **a, t_stack **b, t_bench *bench);
void	sort_medium(t_stack **a, t_stack **b, t_bench *bench);
void	sort_complex(t_stack **a, t_stack **b, t_bench *bench);
void	sort_adaptive(t_stack **a, t_stack **b, t_bench *bench);
void	free_stack(t_stack **a);
void	rotate_top_a(t_stack **a, int pos, t_bench *bench);
void	rotate_top_b(t_stack **b, int pos, t_bench *bench);
void	check_flag(char *str, t_stack **a, t_stack **b, t_bench *bench);
void	assign_ranks(t_stack *a);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_put_double(double n, int fd);
void	handle_input(int argc, char **argv, t_stack **a);
void	handle_sort(int argc, char **argv, t_ctx *ctx);
void	init_bench(t_bench *bench);
void	print_bench(t_bench *bench, double disorder, char *flag);

int		is_sorted(t_stack *a);
int		is_valid(char *str);
int		ft_isspace(int c);
int		has_duplicate(t_stack *a, int n);
int		*stack_to_array(t_stack *a, int size);
int		ft_isdigit(int c);
int		stack_size(t_stack *a);
int		ft_sqroot(int n);
int		find_min_pos(t_stack *a);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		flagged(char *str);
int		ft_strlcpy(char *dst, const char *src, int dst_size);

double	compute_disorder(t_stack *a);
double	count_pairs(int *array, int size);

t_stack	*new_node(int val);

size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*flag_name(char *flag, double disorder);
char	*find_flag(int argc, char	**argv);
char	*ft_strdup(const char *s1);

long	ft_atol(const char *nptr);

#endif
