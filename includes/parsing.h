/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:00:01 by dimatos-          #+#    #+#             */
/*   Updated: 2026/09/15 16:43:04 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "push_swap.h"

int			parse_input(int argc, char **argv, t_stack *a);
int			bench_checker(int *argc, char **argv);
t_strategy	parse_flags(int *argc, char ***argv, t_bench *bench);
int			is_valid_number(const char *str);
long		ft_atol(const char *str);
int			has_duplicate(t_stack *stack, int value);

#endif