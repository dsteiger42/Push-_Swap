/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:32:00 by dsteiger          #+#    #+#             */
/*   Updated: 2024/12/05 14:48:39 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_for_median(int *temp_stack, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (temp_stack[i] > temp_stack[j])
			{
				temp = temp_stack[i];
				temp_stack[i] = temp_stack[j];
				temp_stack[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	sort(t_stack *stack, int size)
{
	if (is_sorted(stack->a, stack->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(stack);
		else if (size == 3)
			sort_three_a(stack);
		else
			quicksort_stack_a(stack, size, 0);
	}
	return (0);
}

int	ft_push(t_stack *stack, int len, int push)
{
	if (push == 0)
		push_b(stack);
	else
		push_a(stack);
	len--;
	return (len);
}

void	util_sort_three_a(t_stack *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		sort_three_a(stack);
	if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			swap_a(stack);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1])
				swap_a(stack);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ft_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				swap_a(stack);
			else if (len++)
				push_a(stack);
		}
	}
	return ;
}

void	util_sort_three_b(t_stack *stack, int len)
{
	if (len == 1)
		push_a(stack);
	else if (len == 2)
	{
		if (stack->b[0] < stack->b[1])
			swap_b(stack);
		while (len--)
			push_a(stack);
	}
	else if (len == 3)
	{
		while (len || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (len == 1 && stack->a[0] > stack->a[1])
				swap_a(stack);
			else if (len == 1 || (len >= 2 && stack->b[0] > stack->b[1])
				|| (len == 3 && stack->b[0] > stack->b[2]))
				len = ft_push(stack, len, 1);
			else
				swap_b(stack);
		}
	}
	return ;
}
