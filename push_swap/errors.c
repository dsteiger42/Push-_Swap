/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:29:20 by dsteiger          #+#    #+#             */
/*   Updated: 2024/12/05 18:14:45 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_stack *stack, char **av, int flag)
{
	int	i;

	if (av && flag)
	{
		i = 0;
		while (av[i])
			free(av[i++]);
		free(av);
	}
	if (stack)
	{
		if (stack->a)
			free(stack->a);
		if (stack->b)
			free(stack->b);
	}
	write (2, "Error\n", 6);
	exit(1);
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
				error(stack, NULL, flag);
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	free_split(char **split_av)
{
	int	i;

	i = 0;
	while (split_av[i])
		free(split_av[i++]);
	free(split_av);
}
