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
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	init_stack(stack);
	stack_add_back(stack, new_node(56));
	stack_add_back(stack, new_node(2));
	stack_add_back(stack, new_node(76));

	print_stack(stack);
	return (0);
}