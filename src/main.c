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

int main(int argc, char *argv[])
{
	t_stack	a;

	init_stack(&a);

	ft_printf("%d\n", parse_input(argc, argv, &a));

	print_stack(&a);
	return (0);
}
