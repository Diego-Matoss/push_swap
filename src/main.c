/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimatos- <rimatos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:06:38 by dimatos-          #+#    #+#             */
/*   Updated: 2026/09/08 21:34:19 by rimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/operations.h"
#include "../includes/parsing.h"
#include "../includes/stack.h"
#include "../includes/debug.h"
#include <unistd.h> // Añadido para usar write()

/* 1. LECTOR DE FLAGS (Separado y limpio) */
static t_strategy	parse_flags(int *argc, char ***argv)
{
	t_strategy	strat;

	strat = ADAPTIVE;
	if (*argc > 1 && ft_strncmp((*argv)[1], "--", 2) == 0)
	{
		if (ft_strncmp((*argv)[1], "--simple", 9) == 0)
			strat = SIMPLE;
		else if (ft_strncmp((*argv)[1], "--medium", 9) == 0)
			strat = MEDIUM;
		else if (ft_strncmp((*argv)[1], "--complex", 10) == 0)
			strat = COMPLEX;
		else if (ft_strncmp((*argv)[1], "--adaptive", 11) != 0)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		(*argc)--;
		(*argv)++;
	}
	return (strat);
}

/* 2. GESTIÓN DE ERRORES (Para no ensuciar el main) */
static void	exit_error(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	// CORRECCIÓN: Error por stderr (fd 2)
	write(2, "Error\n", 6);
	exit(1);
}

/* 3. SUB-RUTINA: ALGORITMOS SIMPLES */
static void	execute_simple(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_small(a, b);
	else
		chunk_sort(a, b);
}

/* 4. CEREBRO CENTRAL (Muy visual y fácil de explicar) */
static void	execute_strategy(t_stack *a, t_stack *b, t_strategy strat, double dis)
{
	if (strat == ADAPTIVE)
	{
		// CORTAFUEGOS: Si son <= 5, forzamos SIMPLE para que no use Radix
		if (a->size <= 5)
			strat = SIMPLE;
		else if (dis < 0.2)
			strat = SIMPLE;
		else if (dis < 0.5)
			strat = MEDIUM;
		else
			strat = COMPLEX;
	}
	if (strat == SIMPLE)
		execute_simple(a, b);
	else if (strat == MEDIUM)
		chunk_sort(a, b);
	else if (strat == COMPLEX)
		radix_sort(a, b);
}

/* 5. MAIN PRINCIPAL (Un índice perfecto) */
int	main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;
	t_strategy	strat;
	double		disorder;

	if (argc == 1)
		return (0);
	strat = parse_flags(&argc, &argv);
	init_stack(&a);
	init_stack(&b);
	if (!parse_input(argc, argv, &a))
		exit_error(&a, &b);
	if (stack_is_sorted(&a))
	{
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	assign_indexes(&a);
	disorder = compute_disorder(&a);
	execute_strategy(&a, &b, strat, disorder);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
