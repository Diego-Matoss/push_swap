/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:34:13 by dimatos-          #+#    #+#             */
/*   Updated: 2026/07/16 18:51:29 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/stack.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	last = stack_last(stack);
	last->next = first;
}

void	ra(t_stack *a, int print)
{
	rotate(a);
	if (print == 1)
		ft_printf("ra\n");
}

void	rb(t_stack *b, int print)
{
	rotate(b);
	if (print == 1)
		ft_printf("rb\n");
}
