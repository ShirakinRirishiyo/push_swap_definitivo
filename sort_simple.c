/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:04:36 by dediaz-f          #+#    #+#             */
/*   Updated: 2025/04/28 14:48:13 by dediaz-f         ###   ########.fr       */
/*         
                                                                   */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_min(t_stack_node **stack, int val)
{
	t_stack_node	*head;
	int				min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	sort_3(t_stack_node **a)
{
	int	top;
	int	mid;
	int	bottom;

	top = (*a)->value;
	mid = (*a)->next->value;
	bottom = (*a)->next->next->value;
	if (top > mid && top > bottom)
	{
		rotate_a(a);
		if ((*a)->value > (*a)->next->value)
			swap_a(*a);
	}
	else if (mid > top && mid > bottom)
	{
		rev_rotate_a(a);
		if ((*a)->value > (*a)->next->value)
			swap_a(*a);
	}
	else if (bottom > top && bottom > mid)
	{
		if ((*a)->value > (*a)->next->value)
			swap_a(*a);
	}
}

void	sort_4(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		rotate_a(stack_a);
	else if (distance == 2)
	{
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (distance == 3)
		rev_rotate_a(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance <= 2)
	{
		while (distance-- > 0)
			rotate_a(stack_a);
	}
	else
	{
		distance = 5 - distance;
		while (distance-- > 0)
			rev_rotate_a(stack_a);
	}
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_short(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		swap_a(*a);
	if (size == 3)
		sort_3(a);
	if (size == 4)
		sort_4(a, b);
	if (size == 5)
		sort_5(a, b);
}
