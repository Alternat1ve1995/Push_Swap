/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:28:58 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/17 16:14:28 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_goto_start(t_arr **arr)
{
	if ((*arr) != NULL)
		if ((*arr)->prev != NULL)
			while ((*arr)->prev != NULL)
				(*arr) = (*arr)->prev;
}

void	ft_goto_end(t_arr **arr)
{
	if ((*arr) != NULL)
		if ((*arr)->next != NULL)
			while ((*arr)->next != NULL)
				(*arr) = (*arr)->next;
}

void	ft_run_normal_lc(int argc, char **argv, t_arr **arr_a, t_arr **arr_b)
{
	int		i;
	int		op;

	i = 1;
	while (++i < argc)
		ft_get_data(arr_a, argv[i]);
	ft_goto_start(arr_a);
	ft_input_validation(arr_a);
	ft_goto_start(arr_a);
	op = ft_read_commands(arr_a, arr_b, 2);
	if (op < (int)((argc - 2) * log(argc) * pow(argc, 0.0899)))
		write(1, "\e[32m", 5);
	else
		write(1, "\e[91m", 5);
	ft_check_sorted(arr_a, arr_b, op, 1);
}

void	ft_run_normal_l(int argc, char **argv, t_arr **arr_a, t_arr **arr_b)
{
	int		i;
	int		op;

	i = 1;
	while (++i < argc)
		ft_get_data(arr_a, argv[i]);
	ft_goto_start(arr_a);
	ft_input_validation(arr_a);
	ft_goto_start(arr_a);
	op = ft_read_commands(arr_a, arr_b, 2);
	if (op < (int)((argc - 2) * log(argc) * pow(argc, 0.0899)))
		write(1, "\e[32m", 5);
	else
		write(1, "\e[91m", 5);
	ft_check_sorted(arr_a, arr_b, op, 0);
}

int		ft_is_flags(int argc, char **argv)
{
	if (argc < 2)
		return (2);
	if (ft_strcmp(argv[1], "-cv") == 0 || ft_strcmp(argv[1], "-vc") == 0)
		return (3);
	else if (ft_strcmp(argv[1], "-dbg") == 0)
		return (3);
	else if (ft_strcmp(argv[1], "-c") == 0)
		return (3);
	else if (ft_strcmp(argv[1], "-v") == 0)
		return (3);
	else if (ft_strcmp(argv[1], "-cl") == 0 || ft_strcmp(argv[1], "-lc") == 0)
		return (3);
	else if (ft_strcmp(argv[1], "-l") == 0)
		return (3);
	return (2);
}
