/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:29:20 by dsteiger          #+#    #+#             */
/*   Updated: 2024/12/02 21:38:56 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	error(t_stack *stack, int flag)
// {
// 	if (stack)
// 	{
// 		if (stack->a)  // Free stack->a if dynamically allocated
// 			free(stack->a);
// 		if (stack->b)  // Free stack->b if dynamically allocated
// 			free(stack->b);
// 		if (flag == 1)  // Only free the stack structure if it was dynamically allocated
// 			free(stack);
// 	}
// 	ft_printf("Error\n");
// 	exit(1);
// }

void	error(t_stack *stack, int flag)
{
	int i;

	i = 0;
	if (flag == 1)
	{
		while (i < stack->size_a)
		{
			free(stack->a[i]);
			i++;
		}
		free(stack);
		ft_printf("Error\n");
		exit(1);
	}
}

int	push_swap_atoi(char *str, t_stack *stack, int flag)
{
	unsigned int		i;
	int					sign;
	unsigned long int	number;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			free(str);
			error(stack, flag);
		}
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	if ((number > 2147483648 && sign == -1) || (number > 2147483647
			&& sign == 1))
	{
		free(str);
		error(stack, flag);
	}
	return (number * sign);
}

int	push_swap_strlen(char **av)
{
	int	i;

	i = 0;
	while (*av)
	{
		av++;
		i++;
	}
	return (i);
}

int	is_sorted(int *stack, int size, int order)
{
	int	i;

	if (order == 0)
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] > stack[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] < stack[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	check_doubles(t_stack *stack, int size, int flag)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack->a[i] == stack->a[j])
				error(stack, flag);
			j++;
		}
		i++;
		j = i + 1;
	}
}
