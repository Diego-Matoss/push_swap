/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimatos- <rimatos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:06:38 by dimatos-          #+#    #+#             */
/*   Updated: 2026/08/04 03:46:07 by rimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/operations.h"
#include "../includes/parsing.h"
#include "../includes/stack.h"
#include "../includes/debug.h"

int main(int argc, char *argv[])
{
    t_stack a;
    t_stack b;          // 1. Declaramos la pila de apoyo
    double  disorder;
    int     percentage; // Movido arriba por la Norminette

    if (argc == 1)
        return (0);
    
    init_stack(&a);
    init_stack(&b);     // 2. Inicializamos B vital para evitar Segmentation Faults

    if (!parse_input(argc, argv, &a))
    {
        free_stack(&a);
        free_stack(&b); // Liberamos B también por si acaso
        ft_printf("Error\n");
        return (1);
    }
    
    if (stack_is_sorted(&a))
    {
        free_stack(&a);
        free_stack(&b);
        return (0);
    }
    
    assign_indexes(&a);
    
    // --- 1. PRUEBA DEL DESORDEN ---
    disorder = compute_disorder(&a);
    percentage = (int)(disorder * 100.0);
    ft_printf("Indice de desorden inicial: %d%%\n", percentage);
    //ft_printf("--- Stack Inicial ---\n");
    //print_stack(&a);
    
    // --- 2. PRUEBA DE ALGORITMOS SIMPLES ---
    //ft_printf("\n--- Ejecutando movimientos ---\n");
    
    if (a.size == 2)
        sort_two(&a);
    else if (a.size == 3)
        sort_three(&a);
    else if (a.size == 4 || a.size == 5)
        sort_small(&a, &b);
	else if (a.size > 5)
        chunk_sort(&a, &b);

    //ft_printf("\n--- Stack Final ---\n");
    //print_stack(&a);
    
    // --- LIMPIEZA FINAL ---
    free_stack(&a);
    free_stack(&b);     // 3. Liberamos B para que Valgrind esté feliz
    return (0);
}
