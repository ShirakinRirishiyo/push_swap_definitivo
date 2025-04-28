/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:38:40 by dediaz-f          #+#    #+#             */
/*   Updated: 2025/02/09 15:38:42 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node *stack)
{
	int	temp;

	if (stack && stack->next)
	{
		temp = stack->content;
		stack->content = stack->next->content;
		stack->next->content = temp;
	}
}

int	swap_a(t_stack_node *s_a)
{
	swap(s_a);
	write(1, "sa\n", 3);
	return (1);
}

int	swap_b(t_stack_node *s_b)
{
	swap(s_b);
	write(1, "sb\n", 3);
	return (1);
}

int	swap_ab(t_stack_node *s_a, t_stack_node *s_b)
{
	swap(s_a);
	swap(s_b);
	write(1, "ss\n", 3);
	return (1);
}
