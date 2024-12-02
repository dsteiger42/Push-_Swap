/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:31:16 by dsteiger          #+#    #+#             */
/*   Updated: 2024/12/02 21:37:42 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **av, int flag)
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
		stack.a[i] = push_swap_atoi(av[i], stack.a, flag);
	check_doubles(stack.a, size, flag);
	sort(&stack, size);
	free(stack.a);
	free(stack.b);
}

int	main(int ac, char **av, int flag)
{
	char	**split_av;
	int		i;

	split_av = NULL;
	if (ac > 1)
	{
		av++;
		if (ac == 2)
		{
			split_av = ft_split(*av, ' ');
			if (!split_av)
				return (1);
			av = split_av;
		}
		push_swap(av, flag);
		if (split_av)
		{
			i = 0;
			while (split_av[i])
				free(split_av[i++]);
			free(split_av);
		}
	}
	return (0);
}
