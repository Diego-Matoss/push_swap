/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 16:35:31 by dimatos-          #+#    #+#             */
/*   Updated: 2026/09/15 16:45:44 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_highest(t_stack *stack)
{
	t_node	*current;
	int		highest;

	current = stack->top;
	highest = current->value;
	while (current != NULL)
	{
		if (current->value > highest)
			highest = current->value;
		current = current->next;
	}
	return (highest);
}

int	find_lowest(t_stack *stack)
{
	t_node	*current;
	int		lowest;

	current = stack->top;
	lowest = current->value;
	while (current != NULL)
	{
		if (current->value < lowest)
			lowest = current->value;
		current = current->next;
	}
	return (lowest);
}
