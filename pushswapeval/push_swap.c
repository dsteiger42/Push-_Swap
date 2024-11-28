/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:31:16 by dsteiger          #+#    #+#             */
/*   Updated: 2024/11/27 19:15:22 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_sorted_stack(t_stack *stack)
{
	int	i;

	if (stack->size_a == 0)
	{
		printf("Stack A is empty.\n");
		return ;
	}
	printf("Stack A (sorted): ");
	i = 0;
	while (i < stack->size_a)
	{
		printf("%d ", stack->a[i]);
		i++;
	}
	printf("\n");
}

void	push_swap(char **av)
{
	t_stack	stack;
	int		size;
	int		i;

	i = -1;
	size = push_swap_strlen(av);
	stack.a = malloc(sizeof(int) * size);
	if (!stack.a)
		return ;
	stack.size_a = size;
	stack.b = malloc(sizeof(int) * size);
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.size_b = 0;
	while (++i < size)
		stack.a[i] = push_swap_atoi(av[i], stack.a);
	check_doubles(stack.a, size);
	sort(&stack, size);
	print_sorted_stack(&stack);
	free(stack.a);
	free(stack.b);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		av++;
		if (ac == 2)
			av = ft_split(*av, ' ');
		push_swap(av);
		return (0);
	}
	return (0);
}
