#include "../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (!node)
	{
		ft_printf("Stack is empty!");
		return ;
	}
	ft_printf("Stack size: %d\n", stack->size);
	while (node->next)
	{
		ft_printf("Value: %d | Index: %d\n", node->value, node->index);
		node = node->next;
	}
	ft_printf("Value: %d | Index: %d\n", node->value, node->index);
}