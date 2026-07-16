/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:06:38 by dimatos-          #+#    #+#             */
/*   Updated: 2026/07/16 18:57:33 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/operations.h"
#include "../includes/parsing.h"
#include "../includes/stack.h"
#include "../includes/debug.h"

// int	is_sorted(int *array)
// {
// 	int	i;

// 	i = 0;
// 	while (array[i])
// 	{
// 		if (array[i] > array[i + 1] && array[i + 1])
// 		return (0);
// 		i++;
// 	}
// 	return (1);
// }

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	init_stack(&a);
	init_stack(&b);
	if (!parse_input(argc, argv, &a))
	{
		free_stack(&a);
		ft_printf("Error\n");
		return (1);
	}
	if (stack_is_sorted(&a))
	{
		free_stack(&a);
		ft_printf("Stack is sorted\n");
		return (0);
	}
	assign_indexes(&a);
	stack_add_back(&b, new_node(3));
	stack_add_back(&b, new_node(2));
	stack_add_back(&b, new_node(1));
	stack_add_back(&b, new_node(4));
	print_stack(&a);
	print_stack(&b);
	return (0);
}
