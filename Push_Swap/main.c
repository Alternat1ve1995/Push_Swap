/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:18:38 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:26:05 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_run_normal(int argc, char **argv, t_arr **arr_a, t_arr **arr_b)
{
	int		i;

	i = 0;
	*arr_b = *arr_b;
	while (++i < argc)
		ft_get_data(arr_a, argv[i]);
	ft_goto_start(arr_a);
	ft_input_validation(arr_a);
	ft_goto_start(arr_a);
}

int			main(int argc, char **argv)
{
	t_arr	*arr_a;
	t_arr	*arr_b;
	int		len;

	arr_a = NULL;
	arr_b = NULL;
	if (argc < 2)
		exit(-1);
	ft_run_normal(argc, argv, &arr_a, &arr_b);
	if (ft_if_sorted(&arr_a, &arr_b) == 1)
		return (0);
	len = ft_lstlen(&arr_a);
	if (len < 4)
	{
		if (len == 3)
			ft_sort_tree_elems(&arr_a, &arr_b);
		else
			ft_sort_two_elems(&arr_a, &arr_b);
		return (1);
	}
	ft_goto_start(&arr_a);
	ft_goto_start(&arr_b);
	ft_run_sorting(&arr_a, &arr_b);
	ft_arrdel(&arr_a, &arr_b);
	return (1);
}
