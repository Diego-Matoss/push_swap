/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:09:29 by dimatos-          #+#    #+#             */
/*   Updated: 2026/07/15 17:13:11 by dimatos-         ###   ########.fr       */
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

void	init_stack(t_stack *stack);
t_node	*new_node(int value);
t_node	*stack_last(t_stack *stack);
int		stack_add_back(t_stack *stack, int value);
void	print_stack(t_stack *stack);
int		parse_input(int argc, char **argv, t_stack *a);
void	assign_indexes(t_stack *stack);
void	free_stack(t_stack *stack);
int		stack_is_sorted(t_stack *stack);

#endif