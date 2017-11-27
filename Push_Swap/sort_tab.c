/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboiko <vboiko@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 20:02:17 by vboiko            #+#    #+#             */
/*   Updated: 2017/05/13 18:26:55 by vboiko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two_elems(t_arr **arr_a, t_arr **arr_b)
{
	ft_goto_start(arr_a);
	ft_goto_start(arr_b);
	if (ft_lstlen(arr_a) < 2)
		return ;
	if ((*arr_a)->nb > (*arr_a)->next->nb)
	{
		if (FUCK && NORME)
		{
			ft_ss(arr_a, arr_b);
			ft_printf("ss\n");
		}
		else
		{
			ft_sa(arr_a, arr_b);
			ft_printf("sa\n");
		}
	}
}

void	ft_sort_int_tab(int **tab, int len)
{
	int		i;
	int		flag;

	i = 1;
	flag = 1;
	while (i < len)
	{
		flag = 0;
		if ((*tab)[i] < (*tab)[i - 1])
		{
			flag = (*tab)[i];
			(*tab)[i] = (*tab)[i - 1];
			(*tab)[i - 1] = flag;
			flag = 1;
			i = 0;
		}
		i++;
	}
}

int		ft_find_median(t_arr **arr, int elems)
{
	int			*numbers;
	int			i;
	int			median;

	i = 0;
	ft_goto_start(arr);
	numbers = (int *)malloc(sizeof(long int) * elems);
	while (i < elems - 1)
	{
		numbers[i] = (int)(*arr)->nb;
		i++;
		(*arr) = (*arr)->next;
	}
	numbers[i] = (int)(*arr)->nb;
	ft_sort_int_tab(&numbers, elems);
	median = (int)numbers[i / 2];
	free(numbers);
	numbers = NULL;
	ft_goto_start(arr);
	return (median);
}
