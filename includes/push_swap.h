/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimatos- <rimatos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:09:29 by dimatos-          #+#    #+#             */
/*   Updated: 2026/08/04 03:40:53 by rimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

double  compute_disorder(t_stack *stack);
void sort_three(t_stack *a);
void sort_two(t_stack *a);
void sort_small(t_stack *a, t_stack *b);
void chunk_sort(t_stack *a, t_stack *b);

#endif