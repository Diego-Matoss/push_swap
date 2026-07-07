#include "../includes/push_swap.h"

void init_stack(t_stack *stack)
{
    stack->top = NULL;
    stack->size = 0;
}

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
    node->index = -1;
	node->next = NULL;
	return (node);
}

t_node	*stack_last(t_stack *stack)
{
    t_node *node;
	if (!stack || !stack->top)
		return (NULL);
    node = stack->top;
	while (node->next)
		node = node->next;
	return (node);
}

void	stack_add_back(t_stack *stack, t_node *node)
{
	t_node	*last;

	if (!stack || !node)
		return ;
	if (stack->top == NULL)
	{
		stack->top = node;
        stack->size++;
		return ;
	}
	last = stack_last(stack);
	last->next = node;
    stack->size++;
}