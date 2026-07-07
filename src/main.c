#include "../includes/push_swap.h"

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

// int	*parsing(int argc, char *argv[])
// {
// 	int i;
// 	int *stack_a;
	
// 	if (argc == 1)
// 		return (0);
// 	stack_a = malloc(sizeof(int) * argc - 1);
// 	if (!stack_a)
// 		return (0);
// 	i = 1;
// 	if (argc > 1)
// 	{
// 		while (i < argc)
// 		{
// 			stack_a[i - 1] = ft_atoi(argv[i]);
// 			i++;
// 		}
// 	}
// 	return (stack_a);
// }

int main()
{
	t_stack	*stack = NULL;
	t_node	*node;
	t_node	*node2;
	t_node	*node3;

	init_stack(stack);
	node = new_node(1);
	node2 = new_node(2);
	node3 = new_node(3);

	stack_add_back(stack, node);
	stack_add_back(stack, node2);
	stack_add_back(stack, node3);

	print_stack(stack);
	return (0);
}