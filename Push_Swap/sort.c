/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 14:36:49 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:27:00 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_needed_to_rotate_top_a(t_arr **arr, int elems, int median)
{
	int		i;
	int		needed;

	i = 1;
	needed = 0;
	while (i <= elems)
	{
		if ((*arr)->nb <= median)
			needed = i;
		if ((*arr)->next != NULL)
			(*arr) = (*arr)->next;
		else
			break ;
		i++;
	}
	ft_goto_start(arr);
	return (needed);
}

int		ft_is_needed_to_rotate_bot_a(t_arr **arr, int elems, int median)
{
	int		i;
	int		needed;

	i = 1;
	needed = 0;
	ft_goto_end(arr);
	while (i <= elems)
	{
		if ((*arr)->nb <= median)
			needed = i;
		if ((*arr)->prev != NULL)
			(*arr) = (*arr)->prev;
		else
			break ;
		i++;
	}
	ft_goto_start(arr);
	return (needed);
}

int		ft_fuck_the_norm(t_arr **arr_a, t_arr **arr_b, int p_e, int median)
{
	if ((*arr_a)->nb <= median)
	{
		ft_ecm("pb", &ft_pb, arr_a, arr_b);
		p_e++;
	}
	else
		ft_ecm("ra", &ft_ra, arr_a, arr_b);
	ft_goto_start(arr_a);
	return (p_e);
}

void	ft_run_global_sorting(t_arr **arr_a, t_arr **arr_b, t_elems **elems)
{
	int		new_elems[2];

	new_elems[1] = 0;
	if (ft_precheck(arr_a, arr_b, elems, &new_elems[0]) == -1)
		new_elems[0] = ft_div_b(arr_a, arr_b, elems);
	if (new_elems[0] < 3)
		ft_sort_two_elems(arr_a, arr_b);
	else if (new_elems[0] == 3)
	{
		if (ft_qsort_tree(arr_a, arr_b) == 0)
			ft_divide_a(arr_a, arr_b, elems, new_elems);
	}
	else
		ft_divide_a(arr_a, arr_b, elems, new_elems);
	if ((*arr_b) != NULL)
		ft_run_global_sorting(arr_a, arr_b, elems);
}

void	ft_run_sorting(t_arr **arr_a, t_arr **arr_b)
{
	t_arr		*parts;
	t_elems		*elems;

	parts = NULL;
	elems = NULL;
	ft_goto_start(arr_a);
	ft_goto_start(arr_b);
	ft_first_sort(arr_a, arr_b, &parts);
	ft_move_parts(&parts, &elems);
	ft_run_global_sorting(arr_a, arr_b, &elems);
	ft_goto_start(&parts);
	while (parts->next != NULL)
	{
		parts = parts->next;
		free(parts->prev);
		parts->prev = NULL;
	}
	free(parts);
	parts = NULL;
	if (elems)
		free(elems);
}
