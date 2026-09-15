/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 21:25:58 by rimatos-          #+#    #+#             */
/*   Updated: 2026/09/15 16:46:41 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operations.h"
#include "../../includes/push_swap.h"
#include "../../includes/stack.h"

static int	get_max_bits(t_stack *a)
{
	t_node	*current;
	int		max_index;
	int		max_bits;

	max_index = 0;
	current = a->top;
	while (current != NULL)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	max_bits = get_max_bits(a);
	size = a->size;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->top->index >> i) & 1) == 1)
				ra(a, 1);
			else
				pb(a, b, 1);
			j++;
		}
		while (b->size > 0)
			pa(a, b, 1);
		i++;
	}
}
