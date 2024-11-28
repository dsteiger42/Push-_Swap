/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:32:07 by dsteiger          #+#    #+#             */
/*   Updated: 2024/11/28 17:05:38 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median(int *pivot, int *stack, int size)
{
	int	*temp_stack;
	int	i;

	temp_stack = (int *)malloc(sizeof(int) * size);
	if (!temp_stack)
		return (0);
	i = 0;
	while (i < size)
	{
		temp_stack[i] = stack[i];
		i++;
	}
	sort_for_median(temp_stack, size);
	*pivot = temp_stack[size / 2];
	free(temp_stack);
	return (1);
}

int	quicksort_stack_a(t_stack *stack, int len, int count_rotate)
{
	int	pivot;
	int	numbers;

	if (is_sorted(stack->a, len, 0) == 1)
		return (1);
	numbers = len;
	if (len <= 3)
	{
		sort_three_a(stack, len);
		return (1);
	}
	if (!median(&pivot, stack->a, len))
		return (0);
	while (len != numbers / 2 + numbers % 2)
	{
		if (stack->a[0] < pivot && (len--))
			push_b(stack);
		else if (++count_rotate)
			rotate_a(stack);
	}
	while (stack->size_a != numbers / 2 + numbers % 2 && count_rotate--)
		reverse_rotate_a(stack);
	return (quicksort_stack_a(stack, numbers / 2 + numbers % 2, 0)
		&& quicksort_stack_b(stack, numbers / 2, 0));
	return (1);
}

int	quicksort_stack_b(t_stack *stack, int len, int count_rotate)
{
	int	pivot;
	int	numbers;

	if (need_lines(stack, len))
		return (1);
	numbers = len;
	if (!median(&pivot, stack->b, len))
		return (0);
	while (len != numbers / 2)
	{
		if (stack->b[0] >= pivot && len--)
			push_a(stack);
		else if (++count_rotate)
			rotate_b(stack);
	}
	while (numbers / 2 != stack->size_b && count_rotate--)
		reverse_rotate_b(stack);
	return (quicksort_stack_a(stack, numbers / 2 + numbers % 2, 0)
		&& quicksort_stack_b(stack, numbers / 2, 0));
}

int	need_lines(t_stack *stack, int len)
{
	if (is_sorted(stack->b, len, 1) == 1)
	{
		while (len--)
			push_a(stack);
	}
	if (len <= 3)
	{
		sort_three_b(stack, len);
		return (1);
	}
	return (0);
}
