/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 21:32:55 by rimatos-          #+#    #+#             */
/*   Updated: 2026/09/14 21:23:35 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operations.h"
#include "../../includes/push_swap.h"
#include "../../includes/stack.h"

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

void	sort_three(t_stack *a)
{
	int	highest;

	if (stack_is_sorted(a))
		return ;
	highest = find_highest(a);
	if (a->top->value == highest)
		ra(a, 1);
	else if (a->top->next->value == highest)
		rra(a, 1);
	if (a->top->value > a->top->next->value)
		sa(a, 1);
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

int	get_distance(t_stack *stack, int value)
{
	t_node	*current;
	int		distance;

	distance = 0;
	current = stack->top;
	while (current != NULL)
	{
		if (current->value == value)
			break ;
		distance++;
		current = current->next;
	}
	return (distance);
}

void	sort_two(t_stack *a)
{
	if (!stack_is_sorted(a))
		sa(a, 1);
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	lowest;
	int	distance;

	while (a->size > 3)
	{
		lowest = find_lowest(a);
		distance = get_distance(a, lowest);
		if (distance <= a->size / 2)
		{
			while (a->top->value != lowest)
				ra(a, 1);
		}
		else
		{
			while (a->top->value != lowest)
				rra(a, 1);
		}
		pb(a, b, 1);
	}
	if (!stack_is_sorted(a))
		sort_three(a);
	while (b->size > 0)
		pa(a, b, 1);
}
