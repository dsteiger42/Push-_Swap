/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:31:39 by dsteiger          #+#    #+#             */
/*   Updated: 2024/11/28 17:05:00 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "printf/ft_printf.h"
# include "push_swap.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}		t_stack;

void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ss(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_rr(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);
void	reverse_rotate_rr(t_stack *stack);
void	push_b(t_stack *stack);
void	push_a(t_stack *stack);

void	error(int *stack);
int		push_swap_strlen(char **av);
int		push_swap_atoi(char *str, int *stack);
int		is_sorted(int *stack, int size, int order);
void	check_doubles(int *stack, int size);
void	print_sorted_stack(t_stack *stack);
void	push_swap(char **av);

int		sort(t_stack *stack, int size);
void	sort_for_median(int *temp_stack, int size);
int		ft_push(t_stack *stack, int len, int push);
void	sort_three_a(t_stack *stack, int len);
int		sort_three_b(t_stack *stack, int len);
int		need_lines(t_stack *stack, int len);

int		median(int *pivot, int *stack, int size);
int		quicksort_stack_a(t_stack *stack, int len, int count_rotate);
int		quicksort_stack_b(t_stack *stack, int len, int count_rotate);

#endif