/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 15:46:31 by dimatos-          #+#    #+#             */
/*   Updated: 2026/09/15 15:48:16 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	check_strategy(char *arg, t_strategy *strat)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		*strat = SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		*strat = MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		*strat = COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		*strat = ADAPTIVE;
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

t_strategy	parse_flags(int *argc, char ***argv, t_bench *bench)
{
	t_strategy	strat;

	strat = ADAPTIVE;
	bench->is_active = 0;
	while (*argc > 1 && ft_strncmp((*argv)[1], "--", 2) == 0)
	{
		if (ft_strncmp((*argv)[1], "--bench", 8) == 0)
			bench->is_active = 1;
		else
			check_strategy((*argv)[1], &strat);
		(*argc)--;
		(*argv)++;
	}
	return (strat);
}
