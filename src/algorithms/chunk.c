/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimatos- <rimatos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 21:33:47 by rimatos-          #+#    #+#             */
/*   Updated: 2026/09/09 21:17:37 by rimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operations.h"
#include "../../includes/push_swap.h"
#include "../../includes/stack.h"

// --- FASE 1: EL EMBUDO (De A para B) ---
void	push_chunks(t_stack *a, t_stack *b)
{
	int	chunk_size;
	int	limit;

	if (a->size <= 100)
		chunk_size = a->size / 5;
	else
		chunk_size = a->size / 11;
	if (chunk_size == 0)
        chunk_size = 1;
	limit = chunk_size;
	while (a->size > 0)
	{
		if (a->top->index < limit)
		{
			pb(a, b, 1);
			if (b->top->index < (limit - (chunk_size / 2)))
				rb(b, 1);
			if (b->size >= limit)
				limit += chunk_size;
		}
		else
		{
			ra(a, 1);
		}
	}
}

// --- EL RADAR DEL FRANCOTIRADOR ---
int	get_max_index_pos(t_stack *b)
{
	t_node	*current;
	int		max_index;
	int		max_pos;
	int		current_pos;

	current = b->top;
	max_index = -1;
	max_pos = 0;
	current_pos = 0;
	while (current != NULL)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = current_pos;
		}
		current_pos++;
		current = current->next;
	}
	return (max_pos);
}

// --- FASE 2: EL FRANCOTIRADOR (De B para A) ---
void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max_pos;

	while (b->size > 0)
	{
		max_pos = get_max_index_pos(b);
		if (max_pos <= b->size / 2)
		{
			while (max_pos > 0)
			{
				rb(b, 1);
				max_pos--;
			}
		}
		else
		{
			while (max_pos < b->size)
			{
				rrb(b, 1);
				max_pos++;
			}
		}
		pa(a, b, 1);
	}
}

// --- LA FUNCIÓN PRINCIPAL ---
void	chunk_sort(t_stack *a, t_stack *b)
{
	push_chunks(a, b);
	push_back_to_a(a, b);
}
