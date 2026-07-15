/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:53:09 by dimatos-          #+#    #+#             */
/*   Updated: 2026/07/15 19:57:27 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/stack.h"

static void	push(t_stack *src, t_stack *dst)
{
	t_node	*aux;
	
	if (!src || !dst || !src->top)
		return ;
	aux = src->top;
	src->top = aux->next;
	aux->next = dst->top;
	dst->top = aux;
	src->size--;
	dst->size++;
}