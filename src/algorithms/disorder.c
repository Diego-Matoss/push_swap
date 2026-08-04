/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimatos- <rimatos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/03 00:29:56 by rimatos-          #+#    #+#             */
/*   Updated: 2026/08/03 00:29:58 by rimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Calcula el índice de desorden de 0.0 (ordenado) a 1.0 (inverso)
double compute_disorder(t_stack *stack)
{
    t_node  *current;
    t_node  *runner;
    double  inversions;
    double  max_inversions;
    double  n;

    // Si la pila no existe, está vacía o tiene un solo número, ya está "ordenada"
    if (!stack || !stack->top || stack->size < 2)
        return (0.0);

    inversions = 0.0;
    n = (double)stack->size; 
    
    // Fórmula matemática del máximo de inversiones posibles
    max_inversions = (n * (n - 1.0)) / 2.0;

    // Contamos las inversiones reales recorriendo la lista hacia adelante
    current = stack->top;
    while (current != NULL)
    {
        runner = current->next;
        while (runner != NULL)
        {
            if (current->value > runner->value)
                inversions++;
            runner = runner->next;
        }
        current = current->next;
    }

    return (inversions / max_inversions);
}