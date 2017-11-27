/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:41:15 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:25:52 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_is_needed_to_rotate(t_arr **arr, int elems, int median)
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

void			ft_sort_tree_elems(t_arr **a, t_arr **b)
{
	ft_goto_start(a);
	if (E1 < E2 && E2 < E3)
		return ;
	else if (E1 < E3 && E3 < E2)
	{
		ft_ecm("rra", &ft_rra, a, b);
		ft_ecm("sa", &ft_sa, a, b);
	}
	else if (E2 < E1 && E1 < E3)
		ft_ecm("sa", ft_sa, a, b);
	else if (E3 < E1 && E1 < E2)
		ft_ecm("rra", &ft_rra, a, b);
	else if (E3 < E2 && E2 < E1)
	{
		ft_ecm("ra", &ft_ra, a, b);
		ft_ecm("sa", &ft_sa, a, b);
	}
	else if (E2 < E3 && E3 < E1)
		ft_ecm("ra", &ft_ra, a, b);
	ft_goto_start(a);
}

static void		ft_make_first_sort(t_arr **arr_a, t_arr **arr_b)
{
	if (ft_lstlen(arr_a) == 3)
		ft_sort_tree_elems(arr_a, arr_b);
	else if (ft_lstlen(arr_a) == 2)
		ft_sort_two_elems(arr_a, arr_b);
}

void			ft_first_sort(t_arr **arr_a, t_arr **arr_b, t_arr **parts)
{
	int		median;
	int		len;
	int		elems;
	int		needed;

	elems = ft_lstlen(arr_a);
	ft_goto_start(arr_a);
	while (ft_lstlen(arr_a) > 3)
	{
		ft_goto_start(arr_a);
		median = ft_find_median(arr_a, ft_lstlen(arr_a));
		len = ft_lstlen(arr_a);
		needed = ft_is_needed_to_rotate(arr_a, len, median) + 1;
		ft_goto_start(arr_a);
		ft_create_elem(parts, 0);
		while (--needed > 0)
		{
			if ((*arr_a)->nb <= median)
				ft_fdiv(arr_a, arr_b, parts, &elems);
			else
				ft_ecm("ra", &ft_ra, arr_a, arr_b);
			ft_goto_start(arr_a);
		}
	}
	ft_make_first_sort(arr_a, arr_b);
}
