/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_usage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 18:29:35 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/17 14:59:57 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_create_elem(t_arr **arr_a, long long int nb)
{
	if ((*arr_a) == NULL)
	{
		(*arr_a) = (t_arr *)malloc(sizeof(t_arr));
		(*arr_a)->nb = (long int)nb;
		(*arr_a)->next = NULL;
		(*arr_a)->prev = NULL;
		return ;
	}
	else
	{
		(*arr_a)->next = (t_arr *)malloc(sizeof(t_arr));
		(*arr_a)->next->nb = (long int)nb;
		(*arr_a)->next->next = NULL;
		(*arr_a)->next->prev = *arr_a;
		(*arr_a) = (*arr_a)->next;
	}
}

void	ft_get_data(t_arr **arr_a, char *str)
{
	if (ft_ifnumber(str) == 0)
		ft_error(2);
	ft_create_elem(arr_a, ft_atoi_ll(str));
}

void	ft_arrdel(t_arr **arr_a, t_arr **arr_b)
{
	if ((*arr_a) == NULL)
		return ;
	if ((*arr_a)->prev != NULL)
		while ((*arr_a)->prev != NULL)
			(*arr_a) = (*arr_a)->prev;
	while ((*arr_a)->next != NULL)
	{
		(*arr_a) = (*arr_a)->next;
		free((*arr_a)->prev);
	}
	if ((*arr_b) == NULL)
		return ;
	if ((*arr_b)->prev != NULL)
		while ((*arr_b)->prev != NULL)
			(*arr_b) = (*arr_b)->prev;
	while ((*arr_b)->next != NULL)
	{
		(*arr_b) = (*arr_b)->next;
		free((*arr_b)->prev);
	}
}

void	ft_run_normal_vc(int argc, char **argv, t_arr **arr_a, t_arr **arr_b)
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
	ft_check_sorted(arr_a, arr_b, op, 1);
}
