#include <stdio.h>
#include <stdlib.h>
#include "../includes/push_swap.h"

void	print_array(int *array)
{
	int i;

	i = 0;
	while (array[i])
	{
		printf("%d\n", array[i]);
		i++;
	}
}

int	is_sorted(int *array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i] > array[i + 1] && array[i + 1])
		return (0);
		i++;
	}
	return (1);
}

int	*parsing(int argc, char *argv[])
{
	int i;
	int *stack_a;
	
	if (argc == 1)
		return (0);
	stack_a = malloc(sizeof(int) * argc - 1);
	if (!stack_a)
		return (0);
	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			stack_a[i - 1] = ft_atoi(argv[i]);
			i++;
		}
	}
	return (stack_a);
}

int main(int argc, char *argv[])
{
	int	*stack_a;

	stack_a = parsing(argc, argv);
	if (is_sorted(stack_a))
		return (free(stack_a), 0);
	print_array(stack_a);
	return (0);
}