/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 21:32:55 by rimatos-          #+#    #+#             */
/*   Updated: 2026/09/09 20:00:38 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operations.h"
#include "../../includes/push_swap.h"
#include "../../includes/stack.h"

// Encuentra el valor más alto en el stack
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

// Ordena exactamente 3 números
void	sort_three(t_stack *a)
{
	int	highest;

	// Si ya está ordenado, no hacemos nada
	if (stack_is_sorted(a))
		return ;
	highest = find_highest(a);
	// Caso A: El más grande está arriba (ej: 3 1 2 o 3 2 1)
	if (a->top->value == highest)
		ra(a, 1);
	// Caso B: El más grande está en medio (ej: 1 3 2 o 2 3 1)
	else if (a->top->next->value == highest)
		rra(a, 1);
// Después de colocar al más grande abajo (o si ya estaba abajo como en 2 1 3),
	// comprobamos si los dos de arriba necesitan intercambiarse.
	if (a->top->value > a->top->next->value)
		sa(a, 1);
}

// Encuentra el valor más bajo en el stack
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

// Encuentra la posición (distancia desde arriba) de un valor específico
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

// Ordena exactamente 2 números
void	sort_two(t_stack *a)
{
	if (!stack_is_sorted(a))
		sa(a, 1);
}

// Ordena 4 o 5 números de forma optimizada
void	sort_small(t_stack *a, t_stack *b)
{
	int	lowest;
	int	distance;

	// Mientras tengamos más de 3 números en A, pasamos el menor a B
	while (a->size > 3)
	{
		lowest = find_lowest(a);
		distance = get_distance(a, lowest);
		// Optimizamos: si está en la primera mitad, giramos hacia arriba (ra)
		if (distance <= a->size / 2)
		{
			while (a->top->value != lowest)
				ra(a, 1);
		}
		// Si está en la segunda mitad, es más corto girar hacia abajo (rra)
		else
		{
			while (a->top->value != lowest)
				rra(a, 1);
		}
		// Una vez que el más pequeño está arriba del todo, lo tiramos a B
		pb(a, b, 1);
	}
	// Ahora quedan exactamente 3 números en A, los ordenamos con tu función
	if (!stack_is_sorted(a))
		sort_three(a);
	// Finalmente, devolvemos todo lo que guardamos en B hacia A
	while (b->size > 0)
		pa(a, b, 1);
}
