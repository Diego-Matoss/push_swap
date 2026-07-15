/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:00:01 by dimatos-          #+#    #+#             */
/*   Updated: 2026/07/15 18:01:13 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "push_swap.h"

int		parse_input(int argc, char **argv, t_stack *a);
void	assign_indexes(t_stack *stack);

#endif