/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimatos- <dimatos-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 17:07:38 by dimatos-          #+#    #+#             */
/*   Updated: 2026/09/11 20:17:22 by dimatos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/stack.h"

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

static int	has_duplicate(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

static int	process_tokens(t_stack *a, char **tokens)
{
	int		i;
	long	num;
	t_node	*new;

	i = 0;
	if (!tokens || !tokens[0]) 
		return (0);
	while (tokens[i])
	{
		if (!is_valid_number(tokens[i]))
			return (0);
		num = ft_atol(tokens[i]);
		if (num < INT_MIN || num > INT_MAX || has_duplicate(a, (int)num))
			return (0);
		new = new_node((int)num);
		if (!new)
			return (0);
		stack_add_back(a, new);
		i++;
	}
	return (1);
}

int	parse_input(int argc, char **argv, t_stack *a)
{
	int		i;
	char	**tokens;

	if (!a || !argv)
		return (0);
	i = 1;
	while (i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		if (!tokens)
			return (0);
		if (!process_tokens(a, tokens))
		{
			free_matrix(tokens);
			return (0);
		}
		free_matrix(tokens);
		i++;
	}
	return (1);
}
