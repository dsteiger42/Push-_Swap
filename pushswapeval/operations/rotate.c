/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:29:55 by dsteiger          #+#    #+#             */
/*   Updated: 2024/11/27 19:23:19 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_a(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	i = 0;
	temp = stack->a[i];
	i++;
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = temp;
	ft_printf("ra\n");
}

void	rotate_b(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_b == 0 || stack->size_b == 1)
		return ;
	i = 0;
	temp = stack->b[i];
	i++;
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = temp;
	ft_printf("rb\n");
}

void	rotate_rr(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_a == 0 || stack->size_a == 1 || (stack->size_b == 0
			|| stack->size_b == 1))
		return ;
	i = 0;
	temp = stack->a[i];
	while (++i < stack->size_a)
		stack->a[i - 1] = stack->a[i];
	stack->a[i - 1] = temp;
	i = 0;
	temp = stack->b[i];
	while (++i < stack->size_b)
		stack->b[i - 1] = stack->b[i];
	stack->b[i - 1] = temp;
	ft_printf("rr\n");
}
