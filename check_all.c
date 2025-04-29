/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:37:32 by dediaz-f          #+#    #+#             */
/*   Updated: 2025/04/29 15:27:59 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = count_arg(argv);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	count_arg(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	all_space(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]) && str[i])
	{
		i++;
	}
	if (str[i] == '\0')
	{
		return (0);
	}
	return (1);
}

int	check_number(char *argv)
{
	int	i;

	i = 0;
	if (argv && argv[i] == '-')
	{
		i++;
		if (argv[i] == ' ' || argv[i] == '\0')
			error_handle("Error");
	}
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_all(int argc, char **argv)
{
	int		i;
	long	tmp_argv;
	char	**tmp_array;

	i = 0;
	if (argc == 2)
	{
		tmp_array = ft_split(argv[1], ' ');
		comprove_split(tmp_array);
	}
	else
		tmp_array = argv + 1;
	while (tmp_array[i])
	{
		tmp_argv = ft_atoi(tmp_array[i]);
		if (tmp_argv < -2147483648 || tmp_argv > 2147483647)
			error_handle("Error");
		if (!check_number(tmp_array[i]) || !all_space(tmp_array[i]))
			error_handle("Error");
		i++;
	}
	if (check_duplicate(tmp_array))
		error_handle("Error");
	if (argc == 2 && tmp_array)
		ft_free(tmp_array);
}
