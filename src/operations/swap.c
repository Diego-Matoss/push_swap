#include "../../includes/push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !stack->top || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void sa(t_stack *a, int print)
{
	swap(a);
	if (print == 1)
		ft_printf("sa\n");
}