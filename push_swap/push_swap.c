/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:31:16 by dsteiger          #+#    #+#             */
/*   Updated: 2024/12/04 16:37:39 by dsteiger         ###   ########.fr       */
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
		stack.a[i] = push_swap_atoi(av[i], &stack, av, flag);
	check_doubles(&stack, size, flag);
	sort(&stack, size);
	free(stack.a);
	free(stack.b);
}

int	main(int ac, char **av)
{
	char	**split_av;
	int		flag;

	split_av = NULL;
	flag = 0;
	if (ac > 1)
	{
		av++;
		if (ac == 2)
		{
			split_av = ft_split(*av, ' ');
			if (!split_av)
				return (1);
			flag = 1;
			av = split_av;
		}
		push_swap(av, flag);
		if (split_av)
			free_split(split_av);
	}
	return (0);
}
