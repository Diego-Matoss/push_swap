#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
}	t_stack;

void init_stack(t_stack *stack);
t_node	*new_node(int value);
t_node	*stack_last(t_stack *stack);
void	stack_add_back(t_stack *stack, t_node *node);
void	print_stack(t_stack *stack);

#endif