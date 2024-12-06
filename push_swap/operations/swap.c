/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:29:49 by dsteiger          #+#    #+#             */
/*   Updated: 2024/12/04 15:47:07 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_a(t_stack *stack)
{
	int	temp;

	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	temp = 0;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	ft_printf("sa\n");
}

void	swap_b(t_stack *stack)
{
	int	temp;

	if (stack->size_b == 0 || stack->size_b == 1)
		return ;
	temp = 0;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	ft_printf("sb\n");
}

void	swap_ss(t_stack *stack)
{
	int	temp;

	if (stack->size_a == 0 || stack->size_a == 1 || (stack->size_b == 0
			|| stack->size_b == 1))
		return ;
	temp = 0;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	ft_printf("ss\n");
}
