/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 18:59:22 by dimatos-          #+#    #+#             */
/*   Updated: 2026/09/10 17:19:47 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/stack.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*last;
	t_node	*before_last;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	before_last = stack->top;
	while (before_last->next->next)
		before_last = before_last->next;
	last = stack_last(stack);
	before_last->next = NULL;
	last->next = stack->top;
	stack->top = last;
}

void	rra(t_stack *a, int print)
{
	reverse_rotate(a);
	if (print == 1)
		ft_printf("rra\n");
	if (a->ops)
		a->ops->rra++;
}

void	rrb(t_stack *b, int print)
{
	reverse_rotate(b);
	if (print == 1)
		ft_printf("rrb\n");
	if (b->ops)
		b->ops->rrb++;
}

void	rrr(t_stack *a, t_stack *b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print == 1)
		ft_printf("rrr\n");
	if (a->ops)
		a->ops->rrr++;
}
