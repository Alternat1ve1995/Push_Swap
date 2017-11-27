/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:35:28 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/17 16:19:28 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	ft_run_dbg(int argc, char **argv, t_arr **arr_a, t_arr **arr_b)
{
	int		i;

	i = 1;
	while (++i < argc)
		ft_get_data(arr_a, argv[i]);
	ft_goto_start(arr_a);
	ft_input_validation(arr_a);
	ft_goto_start(arr_a);
	ft_read_commands_dbg(arr_a, arr_b);
}

static void	ft_run_normal(int argc, char **argv, t_arr **arr_a, t_arr **arr_b)
{
	int		i;
	int		op;

	i = 0;
	while (++i < argc)
		ft_get_data(arr_a, argv[i]);
	ft_goto_start(arr_a);
	ft_input_validation(arr_a);
	ft_goto_start(arr_a);
	op = ft_read_commands(arr_a, arr_b, 0);
	if (op <= (int)((argc - 2) * log(argc) * pow(argc, 0.0899)))
		write(1, "\e[32m", 5);
	else
		write(1, "\e[91m", 5);
	ft_check_sorted(arr_a, arr_b, op, 0);
}

static void	ft_run_normal_c(int argc, char **argv, t_arr **arr_a, t_arr **arr_b)
{
	int		i;
	int		op;

	i = 1;
	while (++i < argc)
		ft_get_data(arr_a, argv[i]);
	ft_goto_start(arr_a);
	ft_input_validation(arr_a);
	ft_goto_start(arr_a);
	op = ft_read_commands(arr_a, arr_b, 0);
	if (op <= (int)((argc - 2) * log(argc) * pow(argc, 0.0899)))
		write(1, "\e[32m", 5);
	else
		write(1, "\e[91m", 5);
	ft_check_sorted(arr_a, arr_b, op, 1);
}

static void	ft_run_normal_v(int argc, char **argv, t_arr **arr_a, t_arr **arr_b)
{
	int		i;
	int		op;

	i = 1;
	while (++i < argc)
		ft_get_data(arr_a, argv[i]);
	ft_goto_start(arr_a);
	ft_input_validation(arr_a);
	ft_goto_start(arr_a);
	op = ft_read_commands(arr_a, arr_b, 1);
	if (op < (int)((argc - 2) * log(argc) * pow(argc, 0.0899)))
		write(1, "\e[32m", 5);
	else
		write(1, "\e[91m", 5);
	ft_check_sorted(arr_a, arr_b, op, 0);
}

int			main(int argc, char **argv)
{
	t_arr	*arr_a;
	t_arr	*arr_b;

	arr_a = NULL;
	arr_b = NULL;
	if (argc < ft_is_flags(argc, argv))
		exit(-1);
	if (ft_strcmp(argv[1], "-cv") == 0 || ft_strcmp(argv[1], "-vc") == 0)
		ft_run_normal_vc(argc, argv, &arr_a, &arr_b);
	else if (ft_strcmp(argv[1], "-dbg") == 0)
		ft_run_dbg(argc, argv, &arr_a, &arr_b);
	else if (ft_strcmp(argv[1], "-c") == 0)
		ft_run_normal_c(argc, argv, &arr_a, &arr_b);
	else if (ft_strcmp(argv[1], "-v") == 0)
		ft_run_normal_v(argc, argv, &arr_a, &arr_b);
	else if (ft_strcmp(argv[1], "-cl") == 0 || ft_strcmp(argv[1], "-lc") == 0)
		ft_run_normal_lc(argc, argv, &arr_a, &arr_b);
	else if (ft_strcmp(argv[1], "-l") == 0)
		ft_run_normal_l(argc, argv, &arr_a, &arr_b);
	else
		ft_run_normal(argc, argv, &arr_a, &arr_b);
	ft_arrdel(&arr_a, &arr_b);
	write(1, "\e[0m\e[39m\e[24m", 14);
	return (1);
}
