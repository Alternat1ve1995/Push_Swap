/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_a_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 14:22:16 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:25:27 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_check_recursion(t_arr **a_a, t_arr **a_b, t_elems **e, int **n_e)
{
	if ((*n_e)[0] + (*n_e)[1] > 2)
		ft_divide_a(a_a, a_b, e, (*n_e));
	else
	{
		while ((*n_e)[1] > 0)
		{
			ft_ecm("rra", &ft_rra, a_a, a_b);
			(*n_e)[1]--;
			(*n_e)[0]++;
		}
		ft_sort_two_elems(a_a, a_b);
	}
}

static void	ft_ololo(t_arr **arr_a, int **arr, int *i)
{
	(*arr)[*i] = (int)(*arr_a)->nb;
	(*arr_a) = (*arr_a)->prev;
	(*i)--;
}

int			ft_find_md_a(t_arr **arr_a, int el[])
{
	int		*arr;
	int		k;
	int		i;

	k = -1;
	i = 0;
	arr = (int *)malloc(sizeof(int) * (el[0] + el[1]));
	ft_goto_start(arr_a);
	while (++k < el[0])
	{
		arr[i] = (int)(*arr_a)->nb;
		(*arr_a) = (*arr_a)->next;
		i++;
	}
	ft_goto_end(arr_a);
	k = -1;
	i = (el[0] + el[1]) - 1;
	while (++k < el[1])
		ft_ololo(arr_a, &arr, &i);
	ft_sort_int_tab(&arr, (el[0] + el[1]));
	i = arr[(el[0] + el[1]) / 2];
	free(arr);
	ft_goto_start(arr_a);
	return (i);
}
