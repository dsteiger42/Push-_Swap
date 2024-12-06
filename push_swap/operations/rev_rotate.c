/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:30:02 by dsteiger          #+#    #+#             */
/*   Updated: 2024/12/04 15:47:01 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate_a(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	i = stack->size_a - 1;
	temp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = temp;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_b == 0 || stack->size_b == 1)
		return ;
	i = stack->size_b - 1;
	temp = stack->b[i];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = temp;
	ft_printf("rrb\n");
}

void	reverse_rotate_rr(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1 || (stack->size_b == 0
			|| stack->size_b == 1))
		return ;
	i = stack->size_a - 1;
	temp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = temp;
	i = stack->size_b - 1;
	temp = stack->b[i];
	while (i--)
		stack->b[i] = stack->b[i - 1];
	stack->b[i] = temp;
	ft_printf("rrr\n");
}
