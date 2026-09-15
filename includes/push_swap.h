/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:09:29 by dimatos-          #+#    #+#             */
/*   Updated: 2026/09/15 15:48:58 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_op_count
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;

}					t_op_count;

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}					t_strategy;

typedef struct s_bench
{
	int			is_active;
	double		disorder;
	t_strategy	strat;
	t_op_count	ops;
}				t_bench;

typedef struct s_stack
{
	t_node			*top;
	int				size;
	t_op_count		*ops;
	int				fd;
}					t_stack;

void				print_bench_stats(t_bench *b);
double				compute_disorder(t_stack *stack);
void				sort_three(t_stack *a);
void				sort_two(t_stack *a);
void				sort_small(t_stack *a, t_stack *b);
void				chunk_sort(t_stack *a, t_stack *b);
void				radix_sort(t_stack *a, t_stack *b);

#endif