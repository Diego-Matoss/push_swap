/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimatos- <rimatos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 21:25:58 by rimatos-          #+#    #+#             */
/*   Updated: 2026/09/08 21:36:38 by rimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/operations.h"
#include "../../includes/push_swap.h"
#include "../../includes/stack.h"

// --- 1. CALCULADORA DE RONDAS ---
// Averigua cuántos bits tiene el número más 
// grande para saber cuántas pasadas dar
static int	get_max_bits(t_stack *a)
{
	t_node	*current;
	int		max_index;
	int		max_bits;

	max_index = 0;
	current = a->top;
	// Buscamos el índice más alto en la pila
	while (current != NULL)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	// Contamos cuántos bits ocupa ese número
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

// --- 2. EL JEFE FINAL: RADIX SORT ---
void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	size;
	int	i; // Nuestra ronda actual (0 es el bit de más a la derecha)
	int	j; // Nuestro contador de cartas por ronda
	max_bits = get_max_bits(a);
	size = a->size;
	i = 0;
	// Bucle de Rondas (Desde el bit que menos vale al que más vale)
	while (i < max_bits)
	{
		j = 0;
		// Bucle para mirar todas las cartas de la Pila A
		while (j < size)
		{
		// Desplazamos el número 'i' posiciones y miramos si termina en 1 o en 0
			if (((a->top->index >> i) & 1) == 1)
				ra(a, 1); // Si es un 1 (Pesado): ¡Al fondo de la noria!
			else
				pb(a, b, 1); // Si es un 0 (Ligero): ¡Apartado a la Pila B!
			j++;
		}
		// Fin de la ronda: Devolvemos todos los "ceros" encima de los "unos"
		while (b->size > 0)
			pa(a, b, 1);
		i++;
		// Pasamos a la siguiente ronda (al siguiente bit más a la izquierda)
	}
}
