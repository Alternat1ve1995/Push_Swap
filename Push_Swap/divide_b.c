/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 15:26:15 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:25:42 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_from_top(t_arr **arr_a, t_arr **arr_b, t_elems **elems, int median)
{
	int		needed;
	int		i;
	int		new_elems;

	i = -1;
	new_elems = 0;
	needed = ft_is_needed_to_rotate_b(arr_b, (*elems)->top, median);
	while (++i < needed)
	{
		ft_goto_start(arr_b);
		if ((*arr_b)->nb >= median)
		{
			ft_ecm("pa", &ft_pa, arr_a, arr_b);
			(*elems)->top--;
			new_elems++;
		}
		else
		{
			ft_ecm("rb", &ft_rb, arr_a, arr_b);
			(*elems)->bot++;
			(*elems)->top--;
		}
		ft_goto_start(arr_b);
	}
	return (new_elems);
}

int	ft_get_from_bot(t_arr **arr_a, t_arr **arr_b, t_elems **elems, int median)
{
	int		needed;
	int		i;
	int		new_elems;

	new_elems = 0;
	needed = ft_is_needed_to_revrotate_b(arr_b, (*elems)->bot, median);
	i = -1;
	while (++i < needed)
	{
		ft_goto_end(arr_b);
		if ((*arr_b)->nb > median)
		{
			ft_ecm("rrb", &ft_rrb, arr_a, arr_b);
			ft_ecm("pa", &ft_pa, arr_a, arr_b);
			(*elems)->bot--;
			new_elems++;
		}
		else
		{
			ft_ecm("rrb", &ft_rrb, arr_a, arr_b);
			(*elems)->bot--;
			(*elems)->top++;
		}
	}
	return (new_elems);
}

int	ft_revrot_b(t_arr **arr_b, int **arr, int *i)
{
	(*arr)[*i] = (int)(*arr_b)->nb;
	if ((*arr_b)->prev != NULL)
		(*arr_b) = (*arr_b)->prev;
	else
		return (0);
	(*i)--;
	return (1);
}

int	ft_find_div_median(t_arr **arr_b, t_elems **elems, int len)
{
	int		*arr;
	int		i;
	int		k;

	k = 0;
	arr = (int *)malloc(sizeof(int) * len);
	i = 0;
	ft_goto_start(arr_b);
	while (++k < (*elems)->top)
	{
		arr[i] = (int)(*arr_b)->nb;
		(*arr_b) = (*arr_b)->next;
		i++;
	}
	arr[i] = (int)(*arr_b)->nb;
	ft_goto_end(arr_b);
	i = len - 1;
	k = -1;
	while (++k < (*elems)->bot)
		if (ft_revrot_b(arr_b, &arr, &i) == 0)
			break ;
	ft_sort_int_tab(&arr, len);
	i = arr[len / 2];
	free(arr);
	return (i);
}

int	ft_div_b(t_arr **arr_a, t_arr **arr_b, t_elems **elems)
{
	int		median;
	int		new_elems;

	ft_goto_start(arr_b);
	median = ft_find_div_median(arr_b, elems, (*elems)->top + (*elems)->bot);
	new_elems = ft_get_from_top(arr_a, arr_b, elems, median);
	new_elems += ft_get_from_bot(arr_a, arr_b, elems, median);
	return (new_elems);
}
