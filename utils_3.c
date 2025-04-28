/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:44:18 by dediaz-f          #+#    #+#             */
/*   Updated: 2025/04/28 14:49:12 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reading_auxiliar(t_stack_node **a, char *av)
{
	t_stack_node	*new;
	char			**numbers;
	int				j;

	numbers = ft_split(av, ' ');
	if (!numbers)
	{
		return ;
	}
	j = 0;
	while (numbers[j])
	{
		new = ft_lstnew(ft_atoi(numbers[j]));
		ft_lstadd_back(a, new);
		j++;
	}
	ft_free(numbers);
}

int	get_distance(t_stack_node **stack, int index)
{
	t_stack_node	*head;
	int				distance;

	distance = 0;
	head = *stack;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}
