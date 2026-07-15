/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:08:46 by dimatos-          #+#    #+#             */
/*   Updated: 2026/07/15 17:08:51 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (!node)
	{
		ft_printf("Stack is empty!");
		return ;
	}
	ft_printf("Stack size: %d\n", stack->size);
	while (node->next)
	{
		ft_printf("Value: %d | Index: %d\n", node->value, node->index);
		node = node->next;
	}
	ft_printf("Value: %d | Index: %d\n", node->value, node->index);
}
