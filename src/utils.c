#include "../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
    t_node *node;

    node = stack->top;
    while (node->next)
    {
        ft_printf("Valor: %d, Indice: %d", node->value, node->index);
        node = node->next;
    }
}