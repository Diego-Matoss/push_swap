/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:06:38 by dimatos-          #+#    #+#             */
/*   Updated: 2026/09/15 15:53:04 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/operations.h"
#include "../includes/parsing.h"
#include "../includes/stack.h"
#include "../includes/debug.h"

static void	exit_error(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	execute_simple(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else
		sort_small(a, b);
}

static void	execute_strategy(t_stack *a, t_stack *b, t_strategy strat, double dis)
{
	if (strat == ADAPTIVE)
	{
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

int	main(int argc, char *argv[])
{
	t_stack		a;
	t_stack		b;
	t_bench		bench;

	if (argc == 1)
		return (0);
	bench.strat = parse_flags(&argc, &argv, &bench);
	init_system(&a, &b, &bench);
	if (!parse_input(argc, argv, &a))
		exit_error(&a, &b);
	if (stack_is_sorted(&a))
	{
		bench.disorder = 0.0;
		print_bench_stats(&bench);
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	assign_indexes(&a);
	bench.disorder = compute_disorder(&a);
	execute_strategy(&a, &b, bench.strat, bench.disorder);
	print_bench_stats(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
