/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:44:18 by dediaz-f          #+#    #+#             */
/*   Updated: 2025/04/27 15:35:09 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free (str);
}

int	error_handle(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(1);
}

void	reading_normal(t_stack_node **a, int ac, char **av)
{
	t_stack_node	*new;
	int				i;

	i = 1;
	while (i < ac)
	{
		new = ft_lstnew(ft_atoi(av[i]));
		ft_lstadd_back(a, new);
		i++;
	}
}

t_stack_node	*find_smallest(t_stack_node **stack) //esta aquí por si acaso
{
	long			smallest;
	t_stack_node	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if ((*stack)->value < smallest)
		{
			smallest = (*stack)->value;
			smallest_node = *stack;
		}
		stack = &(*stack)->next;
	}
	return (smallest_node);
}

void	comprove_split(char **tmp_array)
{
	int		i;
	long	tmp_argv;

	i = 0;
	if (!tmp_array)
		error_handle("Error");
	while (tmp_array[i])
	{
		tmp_argv = ft_atoi(tmp_array[i]);
		if (tmp_argv < -2147483648 || tmp_argv > 2147483647)
		{
			ft_free(tmp_array);
			error_handle("Error");
		}
		if (!check_number(tmp_array[i]) || !all_space(tmp_array[i]))
		{
			ft_free(tmp_array);
			error_handle("Error");
		}
		i++;
	}
}
