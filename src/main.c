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

int main(int argc, char *argv[])
{
	t_stack	a;

	if (argc == 1)
		return (0);
	init_stack(&a);
	if (!parse_input(argc, argv, &a))
	{
		free_stack(&a);
		ft_printf("Error\n");
		return (1);
	}
	assign_indexes(&a);
	print_stack(&a);
	free_stack(&a);

	return (0);
}
