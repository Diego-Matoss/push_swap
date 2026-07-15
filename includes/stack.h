/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:55:02 by dimatos-          #+#    #+#             */
/*   Updated: 2026/07/15 18:42:03 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "push_swap.h"

void	init_stack(t_stack *stack);
t_node	*new_node(int value);
t_node	*stack_last(t_stack *stack);
void	stack_add_back(t_stack *stack, t_node *node);
void	stack_add_front(t_stack *stack, t_node *node);
void	free_stack(t_stack *stack);
int		stack_is_sorted(t_stack *stack);

#endif